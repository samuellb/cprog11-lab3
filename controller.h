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
        
        void run_step();
        void load(std::string);

        void add_place(Place &);
        
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
        
    protected:
        void command_go(std::istream &);
        void command_talk(std::istream &);
        void command_fight(std::istream &);
        void command_drop(std::istream &);
        void command_pick_up(std::istream &);
        void command_save(std::istream &);
        void command_load(std::istream &);

    private:
        Map map;
        std::vector<Actor*> actors;
        std::map<std::string, controller_command> commands;
};

}

#endif



