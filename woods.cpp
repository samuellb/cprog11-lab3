#include <stdexcept>

#include "woods.h"
#include "actor.h"
#include "player.h"
#include "crazy_wolf.h"
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

void Woods::enter(Actor & actor)
{
    if (dynamic_cast<Player*>(&actor) != 0) {
        if (rand() % 3 == 0 && controller.get_actor("crazy") == 0) {
            CrazyWolf * crazy_wolf = new CrazyWolf(controller, controller.get_place("woods38"));
            controller.add_actor(*crazy_wolf);
        }
    }
    Place::enter(actor);
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
        Firewood *wood = new Firewood(controller, Object::make_name("firewood"));
        if (!human->pick_up(*wood)) {
            delete wood;
        }
    }
}



}


