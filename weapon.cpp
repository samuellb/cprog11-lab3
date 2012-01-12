#include "weapon.h"
#include "controller.h"
#include <string>

namespace game {

Weapon::Weapon(Controller &c, std::string n, int weapon_damage) :
    Object(c, n),
    damage(weapon_damage)
{
    
}

Weapon::~Weapon()
{

}

}
