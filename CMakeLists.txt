// utils.h - Header file for utility functions

#ifndef UTILS_H
#define UTILS_H

#include <string>

void saveToFile(const std::string &filename, const std::string &data);
std::string loadFromFile(const std::string &filename);

#endif // UTILS_H
