#ifndef CONTOLLER_H
#define CONTOLLER_H

#include <vector>
#include "types.h"

namespace game {

class Controller {
    
    public:
        Controller();
        
        void run_step();
        
    private:
        std::vector<Actor*> actors;
        
};

}

#endif



