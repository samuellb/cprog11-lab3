#ifndef PLACE_H
#define PLACE_H

#include <set>
#include <map>
#include <string>
#include "types.h"

namespace game {

class Place {
    
    public:
        Place(Controller & controller,
              std::string name, std::string description);
        virtual ~Place();
        
        virtual void enter(Actor &);
        virtual void leave(Actor &);
        
        virtual std::set<std::string> & directions() const = 0;
        virtual Place & neighbor(std::string) const = 0;

        Actor & get_actor(std::string);
        
        std::string name() const;
        std::string description() const;
        
        // TODO pick_up / drop item
        
    protected:
        Controller & controller;
        const std::string name_, description_;
        std::map<std::string, Actor*> actors;
        
        bool has_nonplayer_actors() const;
};

}

#endif



