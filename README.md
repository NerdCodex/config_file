# Configuration File
<b> This repository contains a configuration file named `gpl.conf` that is used to store various settings and parameters for programs in c++. </b>

# Syntax
``` conf
  #Text file
  name [string] = "Subbu Rakesh"
  age [int] = "10"
  username [string] = "subburakesh@gpl.com"
```

# Usage
``` c++
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
```
