#include "actor.h"
#include "controller.h"

namespace game {

Actor::Actor(Controller &c) :
    controller(c)
{
    
}

bool Actor::is_player()
{
    return false;
}


}


