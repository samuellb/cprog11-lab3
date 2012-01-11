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
#include "woods.h"
#include "loader.h"

#include <iostream>
#include <stdexcept>

namespace game {

Loader::Loader(Controller & c) :
    parse_methods(),
    controller(c)
{
    parse_methods[std::string("outdoor")] = &Loader::parse_xy_place<OutdoorPlace>;
    parse_methods[std::string("woods")] = &Loader::parse_xy_place<Woods>;
    parse_methods[std::string("oldman")] = &Loader::parse_actor<OldMan>;
    parse_methods[std::string("player")] = &Loader::parse_actor<Player>;
    parse_methods[std::string("wolf")] = &Loader::parse_actor<Wolf>;
}

Loader::~Loader()
{

}

void Loader::load(std::istream & is)
{
    std::ios::iostate prev_exc = is.exceptions(); // TODO should use RAII
    is.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
   
    std::cout << "Initializing game..." << std::endl;
    std::string command;
    while (true) {
        is >> command;
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

std::string Loader::read_string(std::istream & is) const
{
    char c;
    is >> c;
    if (c != '"') throw std::invalid_argument("expected a string");
    
    std::string s;
    std::getline(is, s, '"');
    return s;
}

template<typename T> void Loader::parse_xy_place(std::istream & is)
{
    char s[200];
    int x, y;
    
    is >> x >> y;
    
    is >> s;
    DirectionSet allowed(s);
    
    std::string name = read_string(is);
    std::string description = read_string(is);
    
    controller.add_place(x, y,
        *new T(controller, name, description, x, y, allowed));
}

Place & Loader::parse_place_reference(std::istream & is) const
{
    return controller.get_place(read_string(is));
}

template<typename T> void Loader::parse_actor(std::istream & is)
{
    controller.add_actor(*new T(controller, parse_place_reference(is)));
}

}


