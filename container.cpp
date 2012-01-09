#include "container.h"
#include "controller.h"
#include "object.h"
#include <vector>

namespace game {

Container::Container(Controller &c) :
    Object(c),
    objects(),
    controller(c),
    used_weight(0),
    used_volume(0)
{
    
}

Container::~Container()
{

}

bool Container::add(Object & object)
{
    if (used_volume + object.volume() <= hold_volume() && used_weight + object.weight() <= hold_weight()) {
        objects.push_back(&object);
        used_volume += object.volume();
        used_weight += object.weight();
        return true;
    }

    return false;
}

bool Container::remove(Object & object)
{
    std::vector<Object *>::iterator it;

    for (it = objects.begin(); it != objects.end(); ++it) {
        if ((*it) == &object) {
            objects.erase(it);
            return true;
        }
    }

    return false;
}

}
