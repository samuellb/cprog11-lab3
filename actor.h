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
        virtual void talk(Actor &) = 0;
        virtual void fight(Actor &) = 0;
        virtual bool drop(Object &) = 0;
        virtual bool pick_up(Object &) = 0;

        virtual std::string name() = 0;
        virtual std::string type() = 0;
        virtual std::string description() = 0;
        virtual bool is_player();

        int health;
        
    protected:
        Controller &controller;
};

}

#endif



