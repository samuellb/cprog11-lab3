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
        void load(std::istream & is);
        
    private:
        Map map;
        std::vector<Actor*> actors;
        
        typedef void (Controller::*parse_method_type)(std::istream & is);
        std::map<std::string, parse_method_type> parse_methods;
        
        void parse_outdoor(std::istream & is);
        
};

}

#endif



