#include "old_man.h"
#include "key.h"
#include "controller.h"
#include <string>

namespace game {

OldMan::OldMan(Controller & c, Place & p) :
    Human(c, p)
{
    
}

OldMan::~OldMan()
{

}

void OldMan::act()
{
}

void OldMan::talked_to(Actor & actor)
{
    if (!is_freezing()) {
        // Has the firewood already
        if (actor.is_player()) {
            std::cout << "Now I don't have to freeze any more :D" << std::endl;
        }
        return;
    }
    
    
    Object * firewood = actor.get_object("firewood");
    if (firewood && pick_up(*firewood)) {
        // Took the firewood
        actor.drop(*firewood);
        
        // Give them a key
        Key *key = new Key(controller);
        if (actor.pick_up(*key)) {
            if (actor.is_player()) {
                std::cout << "Thank you! Now I can make a fire! Here's a key." << std::endl;
            }
        } else {
            delete key;
        }
    } else {
        // No firewood
        if (actor.is_player()) {
            std::cout << "Brrrr. I'm freezing!" << std::endl;
        }
    }
}

std::string OldMan::type() const
{
    return "oldman";
}

std::string OldMan::name() const
{
    return "oldman";
}

std::string OldMan::description() const
{
    return (is_freezing() ?
        "An old man who appears to be freezing." :
        "An old man sitting next to a fire. It looks warm and cozy.");
}

bool OldMan::is_freezing() const
{
    return !has_object("firewood");
}

}

