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

void Actor::go()
{

}

void Actor::talk(Actor & actor)
{

}

void Actor::fight(Actor & actor)
{

}

bool Actor::drop(Object & object)
{
    return false;
}

bool Actor::pick_up(Object & object)
{
    return false;
}

bool Actor::is_player()
{
    return false;
}


}


