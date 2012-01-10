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


template<typename T> void Controller::add_serializable()
{
    load_functions[T::static_type()] = &T::load;
}


Controller::Controller() :
    map(10, 10),
    actors(),
    load_functions()
{
    add_serializable<OutdoorPlace>();
    actors.push_back(new Player(*this));
    actors.push_back(new Wolf(*this));
    actors.push_back(new OldMan(*this));
}

Controller::~Controller()
{
    for (auto actor : actors) {
        delete actor;
    }
}

void Controller::run_step()
{
    for (auto actor : actors) {
        actor->act();
    }

    Player * player = new Player(*this);
    Backpack * bp = new Backpack(*this);
    Key * key = new Key(*this);
    bp->add(*key);

    player->pick_up(*key);
    player->drop(*key);

    delete player;
    delete bp;
    delete key;

    Sword * sword = new Sword(*this, 1000);
    std::cout << sword->description() << std::endl;
    delete sword;
}

Place & Controller::get_room(size_t x, size_t y)
{
    return map.get(x, y);
}

void Controller::add_place(Place & place)
{
    map.add(place);
}

void Controller::load(std::istream & is)
{
    std::ios::iostate prev_exc = is.exceptions(); // TODO should use RAII
    is.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
    
    std::string command;
    while (true) {
        is >> command;
        std::cout << "read >" << command << "<" << std::endl;
        if (command == "end") break;
        if (command.empty()) continue;
        
        auto it = load_functions.find(command);
        if (it == load_functions.end()) {
            std::cerr << "invalid keyword in map/save file: " << command << std::endl;
            break;
        }
        
        // Parse this command
        it->second(*this, is);
    }
    
    is.exceptions(prev_exc);
}

}


