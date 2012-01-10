#include "wolf.h"
#include "controller.h"
#include <string>

namespace game {

Wolf::Wolf(Controller & c, Place & p) :
    Actor(c, p),
    controller(c)
{
    
}

Wolf::~Wolf()
{

}

void Wolf::act()
{

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


