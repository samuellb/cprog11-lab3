#ifndef CONTOLLER_H
#define CONTOLLER_H

#include <vector>
#include "types.h"
#include "map.h"

namespace game {

class Controller {
    
    public:
        Controller();
        
        void run_step();
        
    private:
        Map map;
        std::vector<Actor*> actors;
        
};

}

#endif



