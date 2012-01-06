#include "place.h"
#include "actor.h"
#include <sstream>


namespace game {

Place::Place(std::string name_, std::string description_text_) :
    name(name_),
    description_text(description_text_),
    actors()
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

std::string Place::description()
{
    std::stringstream ss;
    
    ss << description_text << std::endl;
    
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

bool Place::has_nonplayer_actors()
{
    if (actors.empty()) return false;
    
    // check if there's only a player in this place
    if (actors.size() == 1 && (*actors.begin())->is_player()) return false;
    
    return true; // otherwise there must be a non-player actor
}


}


