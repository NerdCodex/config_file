#include<tuple>

int DATABASE_INDEX = 0;
struct DATABASE
{
    std::string idf;
    std::pair< std::string, std::string> value;

};

static struct DATABASE db[100];