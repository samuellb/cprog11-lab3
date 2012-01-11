#include "actor.h"
#include "place.h"
#include "controller.h"

namespace game {

Actor::Actor(Controller &c, Place &p) :
    health(100),
    current_place(&p),
    controller(c)
{
    current_place->enter(*this);
}

Actor::~Actor()
{

}

void Actor::go(std::string direction)
{
    Place & new_place = current_place->neighbor(direction);
    current_place->leave(*this);
    new_place.enter(*this);
    current_place = &new_place;
}

void Actor::talk(Actor & actor)
{

}

void Actor::fight(Actor & actor)
{

}

bool Actor::drop(Object &)
{
    return false;
}

bool Actor::pick_up(Object &)
{
    return false;
}

bool Actor::is_player()
{
    return false;
}

Place & Actor::place()
{
    return *current_place;
}


}


