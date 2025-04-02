#ifndef BOOLEANS_CPP
#define BOOLEANS_CPP

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cctype>
#include <fstream>
#include <string>

bool static isEmptyOrSpaces(const char* str) {
    while (*str) {
        if (!isspace((unsigned char)*str)) {
            return false;
        }
        str++;
    }
    return true;
}


bool static CheckFileAndContinueToNextPhase(const std::string& Filename, const std::string& ExpectedPhrase) {
    std::ifstream file(Filename);
    if (!file) 
        return false; // file doesn't exist

    std::string FileContent;
    std::getline(file, FileContent);
    file.close();

    return FileContent == ExpectedPhrase;

}

#endif // !BOOLEANS_CPP
