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
#include "container.h"

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
    commands(),
    objects()
{
    commands["quit"] = &Controller::command_quit;
    commands["exit"] = &Controller::command_quit;
    commands["go"] = &Controller::command_go;
    commands["talk"] = &Controller::command_talk;
    commands["fight"] = &Controller::command_fight;
    commands["equip"] = &Controller::command_equip;
    commands["drop"] = &Controller::command_drop;
    commands["pick_up"] = &Controller::command_pick_up;
    commands["save"] = &Controller::command_save;
    commands["load"] = &Controller::command_load;
}

Controller::~Controller()
{
    clear();
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
    std::cout << std::endl;
    std::cout << "The kid wakes up from a terrible nightmare, but where is he? Why is he not in his bed?" << std::endl;
    std::cout << "The kid has many questions but standing here will not get him any answers." << std::endl;
    std::cout << "The kid must find his way back home without getting killed." << std::endl;
    std::cout << std::endl;
}

/**
 * Controller::load
 *
 * Loads the game, every actor, object and place.
 */
void Controller::load(std::string filename)
{
    clear();
    std::ifstream file(filename);
    Loader loader(*this);
    loader.load(file);
}

/**
 * Controller::save
 *
 * Saves the game, every actor, object and place.
 * The file format is compatible with load()
 */
void Controller::save(std::string filename)
{
    std::ofstream file(filename);
    map.save(file);
    file << "end" << std::endl;
}

/**
 * Controller::clear
 *
 * Deletes all game state (map, actors, objects...)
 */
void Controller::clear()
{
    map.clear();

    for (auto kv : actors) {
        delete kv.second;
    }
    actors.clear();

    //for (auto kv : objects) {
        //if (kv.second != 0) {
            //std::cout << kv.second->name() << std::endl;
            //delete kv.second;
        //}
    //}
    objects.clear();
}

/**
 * Controller::run_output
 *
 */
void Controller::run_output() const
{
    std::cout << player->get_place()->description();

    Container * container = player->get_container();
    if (container != 0 && !container->is_empty()) {
        std::cout << "Inventory: ";
        for (auto object : container->get_objects()) {
            if (object == player->get_weapon()) {
                std::cout << object->name() << "[Equiped]  ";
            } else {
                std::cout << object->name() << "  ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "You can go: ";
    for (std::string dirname : player->get_place()->directions()) {
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
        if (player->get_place()->has_action(command)) {
            player->get_place()->perform_action(command, *player);
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

    std::cout << std::endl;
}

void Controller::run_step()
{
    for (auto kv : actors) {
        kv.second->act();
    }
}

void Controller::add_place(size_t x, size_t y, Place & place)
{
    map.set(x, y, place);
}

void Controller::add_actor(Actor & actor)
{
    actors.insert(std::pair<std::string, Actor*>(actor.name(), &actor));
    Place * place = actor.get_place();
    place->enter(actor);
}

/**
 * Controller::get_actor
 *
 * Get actor from string name
 */
Actor * Controller::get_actor(std::string actor_name)
{
    auto actor_pair = actors.find(actor_name);
    if (actor_pair != actors.end()) {
        return actor_pair->second;
    }

    return 0;
}

/**
 * Controller::add_object
 *
 * Add object to a place
 */
void Controller::add_object(Object & object, Place & place)
{
    objects.insert(std::pair<std::string, Object*>(object.name(), &object));
    place.add_object(object);
}

/**
 * Controller::add_object
 *
 * Add object to a container
 */
void Controller::add_object(Object & object, Container & container)
{
    if (container.add(object)) {
        objects.insert(std::pair<std::string, Object*>(object.name(), &object));
    }
}

/**
 * Controller::add_object
 *
 * Add object to an actor
 */
void Controller::add_object(Object & object, Actor & actor)
{
    objects.insert(std::pair<std::string, Object*>(object.name(), &object));
    Container * container = dynamic_cast<Container*>(&object);
    if (container != 0) {
        actor.set_container(container);
    }
}

/**
 * Controller::get_object
 *
 * Get object from string name
 */
Object * Controller::get_object(std::string object)
{
    auto object_pair = objects.find(object);
    if (object_pair != objects.end()) {
        return object_pair->second;
    }

    return 0;
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
    if (dynamic_cast<Player*>(&actor) != 0) {
        is_running = false;
        std::cout << "Game over" << std::endl;
    }

    Place * place = actor.get_place();
    place->leave(actor);

    actors.erase(actor.name());

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

    Place * place = player->get_place();
    if (place != 0) {
        Actor * actor = place->get_actor(actor_name);
        if (actor != 0) {
            player->talk(*actor);
        }
    }
}

void Controller::command_fight(std::istream & is)
{
    std::string actor_name;
    is >> actor_name;
    check_args_end(is);

    Place * place = player->get_place();
    if (place != 0) {
        Actor * actor = place->get_actor(actor_name);
        if (actor != 0) {
            player->fight(*actor);
        } else {
            std::cout << "The kid looks stupid trying to fight a non existent entity." << std::endl;
        }
    }
}

void Controller::command_equip(std::istream & is)
{
    std::string object_name;
    is >> object_name;
    check_args_end(is);

    Object * object = get_object(object_name);
    if (object != 0) {
        player->equip(object);
    }
}

void Controller::command_drop(std::istream & is)
{
    std::string object_name;
    is >> object_name;
    check_args_end(is);

    Object * object = get_object(object_name);
    if (object != 0) {
        if (player->drop(*object)) {
            player->get_place()->add_object(*object);
        }
    } else {
        std::cout << "The kid tries to drop a non existent entity." << std::endl;
    }
}

void Controller::command_pick_up(std::istream & is)
{
    std::string object_name;
    is >> object_name;
    check_args_end(is);

    Object * object = get_object(object_name);
    if (object != 0) {
        if (player->pick_up(*object)) {
            player->get_place()->remove_object(*object);
        }
    } else {
        std::cout << "The kid tries to pick up a non existent entity." << std::endl;
    }
}

void Controller::command_save(std::istream & is)
{
    std::string save_name;
    is >> save_name;
    check_args_end(is);

    if (!save_name.empty()) {
        save("saves/" + save_name);
        std::cout << "Game saved." << std::endl;
    } else {
        std::cout << "Failed to save game, please use \"save name\"." << std::endl;
    }
}

void Controller::command_load(std::istream & is)
{
    std::string save_name;
    is >> save_name;
    check_args_end(is);

    if (!save_name.empty()) {
        try {
            load("saves/" + save_name);
            std::cout << "Game loaded." << std::endl;
        } catch (std::exception &) {
            std::cerr << "Failed to load game." << std::endl;
        }
    } else {
        std::cout << "Failed to save game, please use \"load name\"." << std::endl;
    }
}

}
