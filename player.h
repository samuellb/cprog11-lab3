#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "human.h"
#include <string>

namespace game {

class Player : public Human {
    
    public:
        Player(Controller &c);
        ~Player();
    
    protected:
        Controller &controller;
};

}

#endif



