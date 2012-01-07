#ifndef WALKING_ACTOR_H
#define WALKING_ACTOR_H

#include "types.h"
#include "actor.h"
#include <string>

namespace game {

class WalkingActor : Actor {
    
    public:
        WalkingActor(Controller &c);
        virtual ~WalkingActor() = 0;
    
        virtual bool go(/*direction*/) = 0;
    protected:
        Controller &controller;
};

}

#endif



