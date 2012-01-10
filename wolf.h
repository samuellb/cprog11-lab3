#ifndef WOLF_H
#define WOLF_H

#include "types.h"
#include "actor.h"
#include <string>

namespace game {

class Wolf : public Actor {
    
    public:
        Wolf(Controller &, Place &);
        virtual ~Wolf();

        virtual void act();

        virtual std::string name();
        virtual std::string type();
        virtual std::string description();

    protected:
        Controller &controller;
};

}

#endif
