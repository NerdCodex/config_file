#include<iostream>
#include<variant>
#include "lexer.hpp"
#include "read.hpp"
#include "parser.hpp"

using std::string;
using std::cout;
using std::cin;

class Configuration {
public:
    string filename;
    Configuration(const string fname): filename(fname) {
        Lexer lexer(Reader(filename));
        lexer.Lex();
        Parser p;
        p.parse();
    }
    std::variant<int, string, float> fetch(string identifier);
    void putdata (string IDF, string data, string datatype);
};


std::variant<int, string, float> Configuration::fetch(string identifier) {
    int index=0;
    while(db[index].idf != identifier) index++;
    //cout<< "DATATYPE: " << db[index].value.first << " DATA: "<<db[index].value.second<<std::endl;
    if (db[index].value.first == "string") return db[index].value.second;
    else if (db[index].value.first == "int") return std::stoi(db[index].value.second);
    else if (db[index].value.first == "float") return std::stof(db[index].value.second);
    return 0;
}


void Configuration::putdata(string IDF, string data, string datatype) {
    int index = 0;
    while(db[index].idf != IDF && db[index].idf != "\0") {
        index++;
    }
    if (index != DATABASE_INDEX) {
        std::ofstream outputfile;
        outputfile.open(filename, std::ios::app);
        if (!outputfile.is_open()) {
            std::cerr << "Error: Unable to open the file "<< filename << std::endl;
        }
        outputfile << IDF << " [" << datatype << "] " << "= " << "\"" << data << "\";" <<std::endl;

        outputfile.close(); 
    } else {
        std::cerr << IDF << " : " << data << " is already exists." << std::endl;
    }
}


