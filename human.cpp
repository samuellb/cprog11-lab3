#include "human.h"
#include "controller.h"
#include "backpack.h"
#include <string>

namespace game {

Human::Human(Controller & c, Place & p) :
    Actor(c, p, 25),
    controller(c),
    container(new Backpack(c))
{

}

Human::~Human()
{
    delete container;
}

bool Human::drop(Object & object)
{
    return container->remove(object);
}

bool Human::pick_up(Object & object)
{
    return container->add(object);
}

}


