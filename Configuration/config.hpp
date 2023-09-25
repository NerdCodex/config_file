#include<iostream>
#include<variant>
#include "lexer.hpp"
#include "read.hpp"
#include "parser.hpp"


using std::string;
using std::cout;
using std::cin;

class Configuration {
Parser p;
public:
    string filename;
    
    std::map<string, std::pair<string, string>> contents;
    Configuration(const string fname): filename(fname) {
        Lexer lexer(Reader(filename));
        lexer.Lex();
        
        
    }
    std::map<string, std::pair<string, string>> fetch();
    void putdata (string IDF, string data, string datatype);
};

std::map<string, std::pair<string, string>> Configuration::fetch() {
    contents = p.parse();
    return contents;
}



void Configuration::putdata(string IDF, string data, string datatype) {
    
    if (auto element = contents.find(IDF); element == contents.end()) {
        std::ofstream outputfile;
        outputfile.open(filename, std::ios::app);
        if (!outputfile.is_open()) {
            std::cerr << "Error: Unable to open the file "<< filename << std::endl;
        }
        outputfile << IDF << " [" << datatype << "] " << "= " << "\"" << data << "\"" <<std::endl;

        outputfile.close(); 
    } else {
        std::cerr << IDF << " : " << data << " is already exists." << std::endl;
    }
}


