#include<iostream>
#include<string>
#include<map>

using std::cout;

class Parser {
private:
    int pos;
public:
    Parser(): pos(0) {}
    void advance();
    Tokens getcurrenttoken();
    std::map<std::string, std::pair<std::string, std::string>> parse();
};

void Parser::advance() {
    if(pos < TOKEN_INDEX) pos++; 
}

Tokens Parser::getcurrenttoken() {
    if (pos < TOKEN_INDEX) return tok[pos];
    return {"\0", "\0"};
}

std::map<std::string, std::pair<std::string, std::string>> Parser::parse() {
    std::map<std::string, std::pair<std::string, std::string>> config;
    std::string idf, value, dtype;
    while (getcurrenttoken().type != "\0"){
        if (getcurrenttoken().type == "IDENTIFIER") {
            idf = getcurrenttoken().value;
            advance();

        } else if (getcurrenttoken().type == "DATATYPE"){
            dtype = getcurrenttoken().value;
            advance();
            if (getcurrenttoken().type == "DATA") {
                value = getcurrenttoken().value;
                advance();
            } else {
                std::cerr << "Value is not assigned properly for "<< idf << std::endl;
                break;
            }
        } else {
            advance();
        }
        config[idf] = {dtype, value};
    }
    return config;
}