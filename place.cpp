#include "place.h"
#include "actor.h"
#include "controller.h"
#include <sstream>


namespace game {

Place::Place(Controller & c,
             std::string n, std::string d) :
    controller(c),
    name_(n),
    description_(d),
    actors()
{
    controller.add_place(*this);
}

Place::~Place()
{
}

void Place::enter(Actor & actor)
{
    actors.insert(&actor);
}

void Place::leave(Actor & actor)
{
    actors.erase(&actor);
}

std::string Place::name() const
{
    return name_;
}

std::string Place::description() const
{
    std::stringstream ss;
    
    ss << description_ << std::endl;
    
    if (has_nonplayer_actors()) {
        ss << "You see:" << std::endl;
    }
    
    for (auto actor : actors) {
        if (!actor->is_player()) {
            ss << "    " << actor->description() << std::endl;
        }
    }
    
    // TODO items?
    
    return ss.str();
}

bool Place::has_nonplayer_actors() const
{
    if (actors.empty()) return false;
    
    // check if there's only a player in this place
    if (actors.size() == 1 && (*actors.begin())->is_player()) return false;
    
    return true; // otherwise there must be a non-player actor
}


}


