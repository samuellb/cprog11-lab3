#include "human.h"
#include "controller.h"
#include "backpack.h"
#include <string>

namespace game {

Human::Human(Controller &c) :
    Actor(c),
    controller(c),
    container(new Backpack(c))
{

}

Human::Human(const Human & human) :
    Actor(human.controller),
    controller(human.controller),
    container(human.container)
{

}

Human::~Human()
{

}

void Human::go()
{
    // move
}

bool Human::drop(Object & object)
{
    return container->remove(object);
}

bool Human::pick_up(Object & object)
{
    return container->add(object);
}

std::string Human::type()
{
    return "Human";
}

}


