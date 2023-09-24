#include<iostream>
#include<string>
#include "database.hpp"

using std::cout;

class Parser {
private:
    int pos;
public:
    Parser(): pos(0) {}
    void advance();
    Tokens getcurrenttoken();
    void parse();
};

void Parser::advance() {
    if(pos < TOKEN_INDEX) pos++; 
}

Tokens Parser::getcurrenttoken() {
    if (pos < TOKEN_INDEX) return tok[pos];
    return {"\0", "\0"};
}

void Parser::parse() {
    while (getcurrenttoken().type != "\0"){
        if (getcurrenttoken().type == "IDENTIFIER") {
            db[DATABASE_INDEX].idf = getcurrenttoken().value;
            advance();

        } else if (getcurrenttoken().type == "DATATYPE"){
            db[DATABASE_INDEX].value.first = getcurrenttoken().value;
            advance();
            if (getcurrenttoken().type == "DATA") {
                db[DATABASE_INDEX].value.second = getcurrenttoken().value;
                advance();
            } else {
                std::cerr << "Value is not assigned properly for "<< db[DATABASE_INDEX].idf << std::endl;
                break;
            }
        } else {
            advance();
        }
    }
    
}