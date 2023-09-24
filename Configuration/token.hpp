#include<iostream>

int TOKEN_INDEX = 0;


struct Tokens
{
    std::string type;
    std::string value;
};

static struct Tokens tok[100];