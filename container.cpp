#include "container.h"
#include "controller.h"
#include "object.h"
#include <vector>

namespace game {

Container::Container(Controller &c, std::string n) :
    Object(c, n),
    objects(),
    used_weight(0),
    used_volume(0)
{
    
}

Container::~Container()
{
    for (auto object : objects) {
        delete object;
    }
}

bool Container::add(Object & object)
{
    if (objects.count(&object) > 0) return false;
   
    if (used_volume + object.volume() <= hold_volume() && used_weight + object.weight() <= hold_weight()) {
        objects.insert(&object);
        used_volume += object.volume();
        used_weight += object.weight();
        return true;
    }

    return false;
}

bool Container::remove(Object & object)
{
    if (objects.erase(&object) > 0) {
        used_volume -= object.volume();
        used_weight -= object.weight();
        return true;
    }
    
    return false;
}

Object *Container::get_of_type(std::string type)
{
    for (auto o : objects) {
        if (o->type() == type) return o;
    }
    
    return NULL;
}

bool Container::contains(std::string type) const
{
    for (auto o : objects) {
        if (o->type() == type) return true;
    }
    
    return false;
}

}

