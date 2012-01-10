#include "controller.h"
#include "actor.h"
#include "place.h"
#include "backpack.h"
#include "key.h"
#include "player.h"
#include "sword.h"
#include "wolf.h"
#include "old_man.h"
#include "outdoor_place.h"

#include <iostream>
#include <cstring>

namespace game {

Loader::Loader(Controller & c) :
    parse_methods(),
    controller(c)
{
    parse_methods[std::string("outdoor")] = &Loader::parse_outdoor;
}

Loader::~Loader()
{

}

void Loader::load(std::istream & is)
{
    std::ios::iostate prev_exc = is.exceptions(); // TODO should use RAII
    is.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
    
    std::string command;
    while (true) {
        is >> command;
        std::cout << "read >" << command << "<" << std::endl;
        if (command == "end") break;
        if (command.empty()) continue;
        
        auto it = parse_methods.find(command);
        if (it == parse_methods.end()) {
            std::cerr << "invalid keyword in map/save file: " << command << std::endl;
            break;
        }
        
        // Parse this command
        (*this.*it->second)(is);
    }
    
    is.exceptions(prev_exc);
}

void Loader::parse_outdoor(std::istream & is)
{
    char s[200];
    int x, y;
    
    is >> x >> y;
    
    is >> s;
    std::string name(s);
    
    is >> s;
    std::string description(s);
    
    // TODO
    OutdoorPlace::Direction allowed = static_cast<OutdoorPlace::Direction>(255);
    
    new OutdoorPlace(*this, name, description, x, y, allowed);
}


}


