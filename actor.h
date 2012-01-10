#ifndef ACTOR_H
#define ACTOR_H

#include "types.h"
#include <string>

namespace game {

class Actor {
    
    public:
        Actor(Controller &c);
        virtual ~Actor();

        virtual void act() = 0;
        virtual void go();
        virtual void talk(Actor &);
        virtual void fight(Actor &);
        virtual bool drop(Object &);
        virtual bool pick_up(Object &);

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



