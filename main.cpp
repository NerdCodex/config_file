#include <iostream>
#include "Configuration/config.hpp"

int main() {
    Configuration conf("gpl.conf");
    std::cout<<std::get<string>(conf.fetch("username"))<<std::endl;
    return 0;
}