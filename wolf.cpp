#include "wolf.h"
#include "controller.h"
#include <string>

namespace game {

Wolf::Wolf(Controller &c) :
    Actor(c),
    controller(c)
{
    
}

Wolf::~Wolf()
{

}

void Wolf::act()
{

}

void Wolf::go()
{
    // move
}

std::string Wolf::name()
{
    return "Wolfy";
}

std::string Wolf::type()
{
    return "Wolf";
}

std::string Wolf::description()
{
    return "A mad wolf ready to kill...";
}

}


