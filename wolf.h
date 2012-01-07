#ifndef WOLF_H
#define WOLF_H

#include "types.h"
#include "actor.h"
#include <string>

namespace game {

class Wolf : Actor {
    
    public:
        Wolf(Controller &c);
        ~Wolf() = 0;
    
        void go() = 0;

    protected:
        Controller &controller;
};

}

#endif
