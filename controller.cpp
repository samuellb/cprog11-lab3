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
    player(0),
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
}

Controller::~Controller()
{
    for (auto actor : actors) {
        delete actor;
    }
}

/**
 * Controller::run_game
 *
 * Main game loop
 */
void Controller::run_game()
{
    load("maps/map.txt");

    introduction();

    while (is_running) {
        run_output();
        run_input();
        //if (is_running) {
            run_step();
        //}
    }
}

/**
 * Controller::introduction
 *
 * Print the game introduction.
 */
void Controller::introduction() const
{
    std::cout << "The kid wakes up from a nightmare, but where is he? He must find his home without getting killed..." << std::endl;
}

/**
 * Controller::load
 *
 * Loads the game, every actor, object and place.
 */
void Controller::load(std::string filename)
{
    std::ifstream map(filename);
    Loader loader(*this);
    loader.load(map);
}

/**
 * Controller::run_output
 *
 */
void Controller::run_output() const
{
    std::cout << player->place().description();
    
    std::cout << "You can go: ";
    for (std::string dirname : player->place().directions()) {
        std::cout << dirname << "  ";
    }
    std::cout << std::endl;
}

/**
 * Controller::run_input
 *
 * Handle every user input.
 */
void Controller::run_input()
{
    std::cout << "> ";

    std::string line;
    getline(std::cin, line);

    std::string command;
    std::stringstream ss(line);
    ss >> command;

    if (commands.find(command) == commands.end()) {
        // Check if it's an action in the current place
        if (player->place().has_action(command)) {
            player->place().perform_action(command, *player);
        } else {
            std::cerr << "Invalid command: " << command << std::endl;
        }
    } else {
        // Global command
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
}

void Controller::add_place(size_t x, size_t y, Place & place)
{
    map.set(x, y, place);
}

void Controller::add_actor(Actor & actor)
{
    Place & place = actor.place();
    actors.push_back(&actor);
    place.enter(actor);
}

const Place & Controller::get_place(std::string name) const
{
    return map.get(name);
}

const Place & Controller::get_place(size_t x, size_t y) const
{
    return map.get(x, y);
}

void Controller::kill(Actor & actor)
{
    if (actor.name() == "kid") {
        is_running = false;
        std::cout << "Game over" << std::endl;
    }

    for (auto it = actors.begin(); it != actors.end(); ++it) {
        if ((*it) == &actor) {
            actors.erase(it);
        }
    }

    Place & place = actor.place();
    place.leave(actor);

    delete &actor;
}

void Controller::check_args_end(std::istream & is) const
{
    if (is.peek() != EOF) {
        throw std::invalid_argument("invalid number of arguments");
    }
}

/******************************************************************************
 *
 *  Available player commands
 *
 *****************************************************************************/
void Controller::command_quit(std::istream & is)
{
    check_args_end(is);
    is_running = false;
}

void Controller::command_go(std::istream & is)
{
    std::string direction;
    is >> direction;
    check_args_end(is);

    player->go(direction);
}

void Controller::command_talk(std::istream & is)
{
    std::string actor_name;
    is >> actor_name;
    check_args_end(is);

    Actor * actor = player->place().get_actor(actor_name);
    if (actor != 0) {
        player->talk(*actor);
    }
}

void Controller::command_fight(std::istream & is)
{
    std::string actor_name;
    is >> actor_name;
    check_args_end(is);

    Actor * actor = player->place().get_actor(actor_name);
    if (actor != 0) {
        player->fight(*actor);
    } else {
        std::cout << "The kid looks stupied trying to fight a non existent entity." << std::endl;
    }
}

void Controller::command_drop(std::istream & is)
{
    std::string object_name;
    is >> object_name;
    check_args_end(is);

    //player->drop(object_name);
}

void Controller::command_pick_up(std::istream & is)
{
    std::string object_name;
    is >> object_name;
    check_args_end(is);

    //player->pick_up(object_name);
}

void Controller::command_save(std::istream & is)
{
    std::string save_name;
    is >> save_name;
    check_args_end(is);
}

void Controller::command_load(std::istream & is)
{
    std::string save_name;
    is >> save_name;
    check_args_end(is);
}

}
