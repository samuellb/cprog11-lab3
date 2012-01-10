#include "old_man.h"
#include "controller.h"
#include <string>

namespace game {

OldMan::OldMan(Controller & c, Place & p) :
    Human(c, p),
    controller(c)
{
    
}

OldMan::~OldMan()
{

}

void OldMan::act()
{
}

void OldMan::talk(Actor & actor)
{
}

std::string OldMan::name()
{
    return "The old man";
}

std::string OldMan::description()
{
    return "The narrator of this story...";
}

}
