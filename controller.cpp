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
#include "loader.h"

#include <fstream>
#include <iostream>
#include <string>

namespace game {

Controller::Controller() :
    map(10, 10),
    actors()
{
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

void Controller::load(std::string filename)
{
    std::ifstream map(filename);
    Loader loader(*this);
    loader.load(map);
}

void Controller::run_step()
{
    for (auto actor : actors) {
        actor->act();
    }

    //Player * player = new Player(*this);
    //Backpack * bp = new Backpack(*this);
    //Key * key = new Key(*this);
    //bp->add(*key);

    //player->pick_up(*key);
    //player->drop(*key);

    //delete player;
    //delete bp;
    //delete key;

    //Sword * sword = new Sword(*this, 1000);
    //std::cout << sword->description() << std::endl;
    //delete sword;
}

void Controller::add_place(Place & place)
{
    map.add(place);
}

Place & Controller::get_room(size_t x, size_t y)
{
    return map.get(x, y);
}

}
