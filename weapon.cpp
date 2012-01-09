#include "weapon.h"
#include "controller.h"
#include <string>

namespace game {

Weapon::Weapon(Controller &c, unsigned int weapon_damage) :
    Object(c),
    damage(weapon_damage),
    controller(c)
{
    
}

Weapon::~Weapon()
{

}

std::string Weapon::type() const
{
    return "Weapon";
}

}
