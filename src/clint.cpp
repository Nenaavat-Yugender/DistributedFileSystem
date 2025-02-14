// client.cpp - Distributed Storage File System Client

#include <iostream>
#include <fstream>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1" // Change if running on another machine
#define SERVER_PORT 8080

void sendRequest(const std::string &request) {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Connection failed!\n";
        return;
    }

    send(clientSocket, request.c_str(), request.size(), 0);
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    
    std::cout << "Server Response: " << buffer << "\n";
    close(clientSocket);
}

int main() {
    int choice;
    std::string filename, filedata;

    std::cout << "1. Store File\n2. Get File\nEnter choice: ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        std::cout << "Enter filename: ";
        std::getline(std::cin, filename);
        std::cout << "Enter file content: ";
        std::getline(std::cin, filedata);
        sendRequest("STORE " + filename + "\n" + filedata);
    } else if (choice == 2) {
        std::cout << "Enter filename: ";
        std::getline(std::cin, filename);
        sendRequest("GET " + filename);
    } else {
        std::cout << "Invalid choice!\n";
    }
    return 0;
}
