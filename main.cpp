#include <iostream>
#include "Configuration/config.hpp"

int main() {
    std::map<std::string, std::pair<std::string, std::string>> configure;
    Configuration conf("gpl.conf");
    configure = conf.fetch();
    std::cout<<configure["name"].second<<std::endl;
    conf.putdata("username", "subburakesh@gpl.com", "string");
    return 0;
}