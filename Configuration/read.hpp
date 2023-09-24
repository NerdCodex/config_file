#include<iostream>
#include<fstream>
#include<sstream>

std::string Reader(std::string FileName) {
    std::ifstream inputFile(FileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file"<<FileName<<std::endl;
    }

    std::string Content;
    std::string line;

    while (std::getline(inputFile, line)) {
        Content += line + "\n";
    }

    inputFile.close();
    return Content;
}

