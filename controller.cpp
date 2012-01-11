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

#include <stdexcept>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace game {

Controller::Controller() :
    is_running(true),
    map(10, 10),
    actors(),
    commands()
{
    commands["quit"] = &Controller::command_quit;
    commands["exit"] = &Controller::command_quit;
    commands["go"] = &Controller::command_go;
    commands["talk"] = &Controller::command_talk;
    commands["fight"] = &Controller::command_fight;
    commands["drop"] = &Controller::command_drop;
    commands["pick_up"] = &Controller::command_pick_up;
    commands["save"] = &Controller::command_save;
    commands["load"] = &Controller::command_load;

    Place * place = new OutdoorPlace(*this, "test", "afsfgsdf", 1, 1, static_cast<OutdoorPlace::Direction>(255));
    actors.push_back(new Player(*this, *place));
    actors.push_back(new Wolf(*this, *place));
    actors.push_back(new OldMan(*this, *place));
}

Controller::~Controller()
{
    for (auto actor : actors) {
        delete actor;
    }
}

void Controller::run_game()
{
    load("maps/map.txt");

    while(is_running) {
        run_input();
        run_step();
    }
}

void Controller::load(std::string filename)
{
    std::ifstream map(filename);
    Loader loader(*this);
    loader.load(map);
}

void Controller::run_input()
{
    std::string line;
    getline(std::cin, line);

    std::string command;
    std::stringstream ss(line);
    ss >> command;

    if (commands.find(command) == commands.end()) {
        std::cerr << "Invalid command: " << command << std::endl;
    } else {
        try {
            ((*this).*commands[command])(ss);
        } catch (std::invalid_argument &) {
            std::cerr << "Invalid number of arguments to command: " << command << std::endl;
        }
    }
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

const Place & Controller::get_place(std::string name) const
{
    return map.get(name);
}

const Place & Controller::get_place(size_t x, size_t y) const
{
    return map.get(x, y);
}

/******************************************************************************
 * Available player commands
 *****************************************************************************/
void Controller::command_quit(std::istream & is)
{
    is_running = false;
}

void Controller::command_go(std::istream & is)
{
    std::string direction;
    is >> direction;
    if (is.peek() != EOF) {
        throw std::invalid_argument("invalid number of arguments");
    }

    player->go(direction);
}

void Controller::command_talk(std::istream & is)
{
    std::string actor_name;
    is >> actor_name;
    if (is.peek() != EOF) {
        throw std::invalid_argument("invalid number of arguments");
    }
}

void Controller::command_fight(std::istream & is)
{
    std::string actor_name;
    is >> actor_name;
    if (is.peek() != EOF) {
        throw std::invalid_argument("invalid number of arguments");
    }
}

void Controller::command_drop(std::istream & is)
{
    std::string object_name;
    is >> object_name;
    if (is.peek() != EOF) {
        throw std::invalid_argument("invalid number of arguments");
    }
}

void Controller::command_pick_up(std::istream & is)
{
    std::string object_name;
    is >> object_name;
    if (is.peek() != EOF) {
        throw std::invalid_argument("invalid number of arguments");
    }
}

void Controller::command_save(std::istream & is)
{

}

void Controller::command_load(std::istream & is)
{

}

}
