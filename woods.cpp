#include <stdexcept>

#include "woods.h"
#include "actor.h"
#include "controller.h"


namespace game {

Woods::Woods(Controller & controller,
             std::string name, std::string description,
             size_t x, size_t y, DirectionSet allowed) :
    OutdoorPlace(controller, name, description, x, y, allowed)
{
    add_action("chop", static_cast<void (Place::*)(Actor &)>(&Woods::chop));
}

Woods::~Woods()
{
}

std::string Woods::type() const
{
    return "woods";
}

void Woods::chop(Actor & actor)
{
    printf("chopped by %s\n", actor.name().c_str());
}



}


