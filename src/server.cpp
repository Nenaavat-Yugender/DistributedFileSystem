// server.cpp - Distributed Storage File System Server

#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <map>
#include <mutex>
#include <arpa/inet.h>
#include <unistd.h>
#include "utils.h"

std::mutex file_mutex;
std::map<std::string, std::string> fileStorage; // Simulated distributed storage

void handleClient(int clientSocket) {
    char buffer[1024];
    recv(clientSocket, buffer, sizeof(buffer), 0);
    
    std::string request(buffer);
    std::string response;

    if (request.rfind("STORE ", 0) == 0) {
        size_t pos = request.find('\n');
        if (pos != std::string::npos) {
            std::string filename = request.substr(6, pos - 6);
            std::string filedata = request.substr(pos + 1);
            
            std::lock_guard<std::mutex> lock(file_mutex);
            fileStorage[filename] = filedata;
            saveToFile(filename, filedata);
            response = "File stored successfully";
        }
    } else if (request.rfind("GET ", 0) == 0) {
        std::string filename = request.substr(4);
        
        std::lock_guard<std::mutex> lock(file_mutex);
        if (fileStorage.find(filename) != fileStorage.end()) {
            response = fileStorage[filename];
        } else {
            response = loadFromFile(filename);
        }
    }
    
    send(clientSocket, response.c_str(), response.size(), 0);
    close(clientSocket);
}

void startServer(int port) {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);

    std::cout << "Server listening on port " << port << std::endl;
    
    while (true) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        std::thread(handleClient, clientSocket).detach();
    }
}

int main() {
    int port = 8080;
    startServer(port);
    return 0;
}