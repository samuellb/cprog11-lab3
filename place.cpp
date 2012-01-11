#include "place.h"
#include "actor.h"
#include "object.h"
#include "controller.h"

#include <stdexcept>
#include <sstream>

namespace game {

Place::Place(Controller & c,
             std::string n, std::string d) :
    controller(c),
    name_(n),
    description_(d),
    actors(),
    objects(),
    action_methods()
{
}

Place::~Place()
{
}

void Place::enter(Actor & actor)
{
    actors.insert(std::make_pair(actor.name(), &actor));
}

void Place::leave(Actor & actor)
{
    actors.erase(actor.name());
}

Actor * Place::get_actor(std::string actor)
{
    auto actor_pair = actors.find(actor);
    if (actor_pair != actors.end()) {
        return actor_pair->second;
    }

    return 0;
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
        ss << "The kid looks around and sees:" << std::endl;
    }
    
    for (auto kv : actors) {
        if (!kv.second->is_player()) {
            ss << "    " << kv.second->name() << ": " << kv.second->description() << std::endl;
        }
    }

    for (auto kv : objects) {
        ss << "    " << kv.second->name() << ": " << kv.second->description() << std::endl;
    }

    return ss.str();
}

bool Place::has_nonplayer_actors() const
{
    if (actors.empty()) return false;
    
    // check if there's only a player in this place
    if (actors.size() == 1 && (*actors.begin()).second->is_player()) return false;
    
    return true; // otherwise there must be a non-player actor
}


/* Actions */
void Place::add_action(std::string name, void (Place::*method)(Actor &))
{
    action_methods.insert(std::make_pair(name, method));
}

std::set<std::string> Place::actions() const
{
    std::set<std::string> names;
    for (auto kv : action_methods)
    {
        names.insert(kv.first);
    }
    return names;
}

bool Place::has_action(std::string name) const
{
    return action_methods.find(name) != action_methods.end();
}

void Place::perform_action(std::string name, Actor & actor)
{
    (this->*action_methods[name])(actor);
}


}


