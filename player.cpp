#include "player.h"
#include "controller.h"

namespace game {

Player::Player(Controller &c) :
    Human(c),
    controller(c)
{
    
}

}


