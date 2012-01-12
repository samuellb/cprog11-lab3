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
#include "portal.h"
#include "loader.h"
#include "container.h"

#include <iostream>
#include <stdexcept>

namespace game {

Loader::Loader(Controller & c) :
    parse_methods(),
    controller(c)
{
    parse_methods[std::string("outdoor")] = &Loader::parse_xy_place<OutdoorPlace>;
    parse_methods[std::string("woods")] = &Loader::parse_xy_place<Woods>;
    parse_methods[std::string("portal")] = &Loader::parse_xy_place<Portal>;
    parse_methods[std::string("oldman")] = &Loader::parse_actor<OldMan>;
    parse_methods[std::string("kid")] = &Loader::parse_actor<Player>;
    parse_methods[std::string("wolf")] = &Loader::parse_actor<Wolf>;
    parse_methods[std::string("sword")] = &Loader::parse_object<Sword>;
    parse_methods[std::string("key")] = &Loader::parse_object<Key>;
    parse_methods[std::string("backpack")] = &Loader::parse_object<Backpack>;
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

Actor * Loader::parse_actor_reference(std::istream & is) const
{
    return controller.get_actor(read_string(is));
}

Object * Loader::parse_object_reference(std::istream & is) const
{
    return controller.get_object(read_string(is));
}

template<typename T> void Loader::parse_actor(std::istream & is)
{
    controller.add_actor(*new T(controller, parse_place_reference(is)));
}

template<typename T> void Loader::parse_object(std::istream & is)
{
    std::string reference_type;
    is >> reference_type;
    if (reference_type == "place") {
        controller.add_object(*new T(controller), parse_place_reference(is));
    } else if (reference_type == "actor") {
        controller.add_object(*new T(controller), *parse_actor_reference(is));
    } else if (reference_type == "container") {
        Container * container = dynamic_cast<Container*>(parse_object_reference(is));
        if (container != 0) {
            controller.add_object(*new T(controller), *container);
        }
    }
}

}


