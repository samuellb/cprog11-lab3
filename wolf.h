#ifndef WOLF_H
#define WOLF_H

#include "types.h"
#include "actor.h"
#include <string>

namespace game {

class Wolf : public Actor {
    
    public:
        Wolf(Controller &c);
        virtual ~Wolf() = 0;
    
        virtual void go() = 0;

    protected:
        Controller &controller;
};

}

#endif
