#include "weapon.h"
#include "controller.h"
#include <string>

namespace game {

Weapon::Weapon(Controller &c, int weapon_damage) :
    Object(c),
    damage(weapon_damage),
    controller(c)
{
    
}

Weapon::~Weapon()
{

}

}
