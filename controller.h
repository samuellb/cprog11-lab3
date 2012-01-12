#ifndef CONTOLLER_H
#define CONTOLLER_H

#include <vector>
#include <map>
#include <iostream>
#include "types.h"
#include "map.h"

namespace game {

typedef void (Controller::*controller_command)(std::istream &);

class Controller {
    
    public:
        Controller();
        ~Controller();
        
        void run_game();
        void load(std::string);
        void save(std::string);
        void clear();
        void exit();

        inline void set_player(Player & p) { player = &p; }

        void add_place(size_t x, size_t y, Place &);
        void add_actor(Actor &);
        void add_object(Object &, Place &);
        void add_object(Object &, Container &);
        void add_object(Object &, Actor &);
        void add_object(Object & object);

        Object * get_object(std::string);
        Actor * get_actor(std::string);
        
        const Place & get_place(std::string) const;
        inline Place & get_place(std::string name)
        {
            return const_cast<Place&>(const_cast<const Controller*>(this)->get_place(name));
        }
        
        const Place & get_place(size_t x, size_t y) const;
        inline Place & get_place(size_t x, size_t y)
        {
            return const_cast<Place&>(const_cast<const Controller*>(this)->get_place(x, y));
        }

        void kill(Actor & actor);
        std::string make_identifier(std::string);
        
    protected:
        bool is_running;

        void introduction() const;
        void run_output() const;
        void run_input();
        void run_step();
        
        void check_args_end(std::istream & is) const;

        void command_quit(std::istream &);
        void command_go(std::istream &);
        void command_talk(std::istream &);
        void command_fight(std::istream &);
        void command_equip(std::istream &);
        void command_drop(std::istream &);
        void command_pick_up(std::istream &);
        void command_save(std::istream &);
        void command_load(std::istream &);

    private:
        Player * player;
        Map map;
        std::map<std::string, Actor*> actors;
        std::map<std::string, controller_command> commands;
        std::map<std::string, Object*> objects;
        int next_identifier;

        // disable copy and assignment
        Controller(const Controller &);
        Controller & operator=(const Controller &);
        
        friend class Loader; // needs to set next_identifier
};

}

#endif



