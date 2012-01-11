#include "wolf.h"
#include "controller.h"
#include <string>

namespace game {

Wolf::Wolf(Controller & c, Place & p) :
    Actor(c, p, 40),
    controller(c)
{
    
}

Wolf::~Wolf()
{

}

void Wolf::act()
{

}

std::string Wolf::type() const
{
    return "wolf";
}

std::string Wolf::name() const
{
    return "Wolfy";
}

std::string Wolf::description() const
{
    return "A mad wolf ready to kill...";
}

}


