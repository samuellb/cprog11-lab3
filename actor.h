#ifndef ACTOR_H
#define ACTOR_H

#include "types.h"

namespace game {

class Actor {
    
    public:
        Actor(Controller &c);
        virtual ~Actor() = 0;
        
        virtual void act() = 0;
        
    protected:
        Controller &controller;
};

}

#endif



