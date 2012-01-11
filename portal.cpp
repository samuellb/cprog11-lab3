#include <stdexcept>

#include "portal.h"
#include "actor.h"
#include "controller.h"


namespace game {

Portal::Portal(Controller & controller,
             std::string name, std::string description,
             size_t x, size_t y, DirectionSet allowed) :
    OutdoorPlace(controller, name, description, x, y, allowed)
{
    add_action("portal", static_cast<void (Place::*)(Actor &)>(&Portal::portal));
}

Portal::~Portal()
{
}

std::string Portal::type() const
{
    return "portal";
}

void Portal::portal(Actor & actor)
{
    if (actor.has_object("key")) {
        
        if (actor.is_player()) {
            std::cout << "As you approach the portal it lights up. You swallow, and walk through it..." << std::endl;
        }
        
        actor.teleport("portal target");
        
    } else if (actor.is_player()) {
        std::cout << "It's just a strange stone with a man-sized hole in it..." << std::endl;
    }
}


}


