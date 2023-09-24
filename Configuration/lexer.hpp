#include "token.hpp"
#include<iostream>
#include<string>

int Line=0;

class Lexer {
    int pos;
    std::string Content;
public:
    Lexer(const std::string input): Content(input), pos(0) {}

    void advance();
    char getcurrentchar();
    void skipwhitespace();
    void skipnewlines();
    void nexttoken();
    void skipcomment();
    std::string getstring();
    std::string getidentifier();
    std::string getdatatype(); 
    void Lex();
};

void Lexer::advance() {
    if (pos < Content.length()) pos++;
}

char Lexer::getcurrentchar() {
    if (pos < Content.length() && (Content[pos] != ' ' || Content[pos] != '\t')) return Content[pos];
    else return '\0';
}

void Lexer::skipwhitespace() {
    if (getcurrentchar() == ' ' || getcurrentchar() == '\t')
        advance();
}

void Lexer::skipnewlines() {
    if (getcurrentchar() == '\n'){ advance(), Line++; }
}

std::string Lexer::getstring() {
    std::string String;
    advance(); // To skip the ' " '
    while (getcurrentchar() != '"'){
        String+=getcurrentchar();
        advance();
    } 

    advance();
    return String;
}

std::string Lexer::getidentifier() {
    std::string idf;
    while (isalnum(getcurrentchar())) {
        idf += getcurrentchar();
        advance();
    }

    advance();
    return idf;
}

std::string Lexer::getdatatype() {
    std::string datatype;
    advance();
    while (getcurrentchar() != ']') {
        datatype += getcurrentchar();
        advance();
    }
    advance();

    return datatype;
}

void Lexer::skipcomment() {
    if (getcurrentchar() == '#')
        while (getcurrentchar() != '\n'){
            advance();
        }
}

void Lexer::nexttoken() {
    while (getcurrentchar() != '\0') {
        if (getcurrentchar() == ' ' || getcurrentchar() == '\t') skipwhitespace();
        if (getcurrentchar() == '\n') skipnewlines();
        if (isalnum(getcurrentchar())) {
            tok[TOKEN_INDEX].type = "IDENTIFIER";
            tok[TOKEN_INDEX].value = getidentifier();
            TOKEN_INDEX++;
        }

        if (getcurrentchar() == '['){
            tok[TOKEN_INDEX].type = "DATATYPE";
            tok[TOKEN_INDEX].value = getdatatype();
            TOKEN_INDEX++;
        } else if (getcurrentchar() == '"') {
            tok[TOKEN_INDEX].type = "DATA";
            tok[TOKEN_INDEX].value = getstring();
            TOKEN_INDEX++;
        } else if (getcurrentchar() == '#') skipcomment();
        else {
            advance();
        }
    }
}

void Lexer::Lex() {
    do {
        nexttoken();
    } while(pos < Content.length());

}