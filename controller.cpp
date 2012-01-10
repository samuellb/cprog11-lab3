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

Controller::Controller() :
    map(10, 10),
    actors(),
    parse_methods()
{
    parse_methods[std::string("outdoor")] = &Controller::parse_outdoor;
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

void Controller::load(std::istream & is)
{
    std::ios::iostate prev_exc = is.exceptions(); // TODO should use RAII
    is.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
    
    char command[50];
    is >> command;
    while (std::strcmp(command, "end")) {
        if (std::strcmp(command, "")) {
            (*this.*parse_methods[command])(is);
        }
    }
    
    is.exceptions(prev_exc);
}

void Controller::parse_outdoor(std::istream & is)
{
    char s[200];
    int x, y;
    
    is >> x >> y;
    
    is >> s;
    std::string name(s);
    
    is >> s;
    std::string description(s);
    
/*    is >> s;
    if (strcmp(s, "(")) break;
    
    is >> s;
    OutdoorPlace::Direction dir(s);*/
    // TODO
    OutdoorPlace::Direction allowed = static_cast<OutdoorPlace::Direction>(255);
    
    new OutdoorPlace(*this, name, description, x, y, allowed);
}


}


