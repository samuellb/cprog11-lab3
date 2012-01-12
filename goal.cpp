#include <stdexcept>

#include "goal.h"
#include "actor.h"
#include "controller.h"


namespace game {

Goal::Goal(Controller & controller,
             std::string name, std::string description,
             size_t x, size_t y, DirectionSet allowed) :
    OutdoorPlace(controller, name, description, x, y, allowed)
{
}

Goal::~Goal()
{
}

std::string Goal::type() const
{
    return "goal";
}

void Goal::enter(Actor & actor)
{
    if (actor.is_player()) {
        // Win!
        std::cout << description() << std::endl;
        controller.exit();
    }
}



}


