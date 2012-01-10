#ifndef CONTOLLER_H
#define CONTOLLER_H

#include <vector>
#include "types.h"
#include "map.h"

namespace game {

class Controller {
    
    public:
        Controller();
        ~Controller();
        
        void run_step();
        Place & get_room(size_t x, size_t y);
        
    private:
        Map map;
        std::vector<Actor*> actors;
        
};

}

#endif



