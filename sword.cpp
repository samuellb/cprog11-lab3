#include "sword.h"
#include "controller.h"
#include <string>

namespace game {
    
Sword::Sword(Controller &c, unsigned int weapon_damage) :
    Weapon(c, weapon_damage),
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
    return "The kids sword";
}

std::string Sword::type() const
{
    return "Weapon|Sword";
}

std::string Sword::description() const
{
    return "The kids sword was made by an unknown swordsmith in the southern part of Caelondia";
}

}
