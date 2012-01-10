#ifndef HUMAN_H
#define HUMAN_H

#include "types.h"
#include "actor.h"
#include "container.h"
#include <string>

namespace game {

class Human : public Actor {
    
    public:
        Human(Controller &, Place &);
        virtual ~Human();
    
        virtual bool drop(Object &);
        virtual bool pick_up(Object &);

        virtual std::string name() = 0;
        virtual std::string type();
        virtual std::string description() = 0;

    protected:
        Controller &controller;
        Container * container;
};

}

#endif
