#include <stdexcept>

#include "woods.h"
#include "actor.h"
#include "controller.h"
#include "firewood.h"
#include "human.h"


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
    // Only humans can pick up stuff (or chop down trees...)
    Human *human = dynamic_cast<Human*>(&actor);
    if (human) {
        if (actor.is_player()) {
            std::cout << "You chopped down a tree and cut it in pieces. Took a couple of hours." << std::endl;
        }
        
        // Give some firewood to the actor
        Firewood *wood = new Firewood(controller);
        if (!human->pick_up(*wood)) {
            delete wood;
        }
    }
}



}


