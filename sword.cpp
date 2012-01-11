#include "sword.h"
#include "controller.h"
#include <string>

namespace game {
    
Sword::Sword(Controller &c) :
    Weapon(c, 17),
    controller(c)
{
    
}

Sword::~Sword()
{

}

int Sword::weight()
{
    return 13;
}

int Sword::volume()
{
    return 10;
}

int Sword::price()
{
    return 140;
}

std::string Sword::name() const
{
    return "sword";
}

std::string Sword::type() const
{
    return "weapon|sword";
}

std::string Sword::description() const
{
    return "The kids sword was made by an unknown swordsmith in the southern part of Caelondia";
}

}
