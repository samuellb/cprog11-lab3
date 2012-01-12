#include "human.h"
#include "controller.h"
#include "backpack.h"
#include "weapon.h"
#include <string>

namespace game {

Human::Human(Controller & c, Place & p) :
    Actor(c, p, 25)
{

}

Human::~Human()
{
    delete current_container;
}

bool Human::equip(Object * object)
{
    if (has_object(object->name())) {
        Weapon * weapon = dynamic_cast<Weapon*>(object);
        if (weapon != 0) {
            set_weapon(weapon);
            return true;
        }
    }

    return false;
}

bool Human::drop(Object & object)
{
    if (current_container != 0) {
        return current_container->remove(object);
    }

    return false;
}

bool Human::pick_up(Object & object)
{
    if (current_container != 0) {
        return current_container->add(object);
    }

    return false;
}

bool Human::has_object(std::string name) const
{
    if (current_container != 0) {
        return current_container->contains(name);
    }

    return false;
}

}


