#include "actor.h"
#include "controller.h"

namespace game {

Actor::Actor(Controller &c) :
    health(100),
    controller(c)
{
    
}

Actor::~Actor()
{

}

bool Actor::is_player()
{
    return false;
}


}


