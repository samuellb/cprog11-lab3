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
        
        void add_place(Place & place);
        
    private:
        Map map;
        std::vector<Actor*> actors;
        
        typedef void (*load_function)(Controller & controller, std::istream & is);
        std::map<std::string, load_function> load_functions;
        
        template<typename T> void add_serializable();
};

}

#endif



