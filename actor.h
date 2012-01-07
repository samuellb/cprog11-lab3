#ifndef ACTOR_H
#define ACTOR_H

#include "types.h"
#include <string>

namespace game {

class Actor {
    
    public:
        Actor(Controller &c);
        virtual ~Actor() = 0;

        virtual void act() = 0;
        virtual void go() = 0;

        virtual std::string name() = 0;
        virtual std::string description() = 0;
        virtual bool is_player();
        
    protected:
        Controller &controller;
};

}

#endif



