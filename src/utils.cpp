// utils.cpp - Helper functions for file operations

#include "utils.h"
#include <fstream>
#include <iostream>

void saveToFile(const std::string &filename, const std::string &data) {
    std::ofstream outFile("storage/" + filename);
    if (outFile) {
        outFile << data;
        outFile.close();
    } else {
        std::cerr << "Error saving file: " << filename << "\n";
    }
}

std::string loadFromFile(const std::string &filename) {
    std::ifstream inFile("storage/" + filename);
    if (inFile) {
        std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        inFile.close();
        return content;
    }
    return "File not found";
}
