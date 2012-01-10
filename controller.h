#ifndef CONTOLLER_H
#define CONTOLLER_H

#include <vector>
#include <map>
#include <iostream>
#include "types.h"
#include "map.h"

namespace game {

class Controller {
    
    public:
        Controller();
        ~Controller();
        
        void run_step();
        Place & get_room(size_t x, size_t y);
        void load(std::string);

        void add_place(Place &);
        
    private:
        Map map;
        std::vector<Actor*> actors;
};

}

#endif



