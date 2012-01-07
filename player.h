#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "wolf.h"
#include <string>

namespace game {

class Player : Wolf {
    
    public:
        Player(Controller &c);
        ~Player() = 0;
    
    protected:
        Controller &controller;
};

}

#endif



