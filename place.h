#ifndef PLACE_H
#define PLACE_H

#include <set>
#include <string>
#include <iostream>
#include "types.h"

namespace game {

class Place : public Serializable {
    
    public:
        Place(Controller & controller_,
              std::string name_, std::string description_text_);
        virtual ~Place();
        
        virtual void enter(Actor & actor);
        virtual void leave(Actor & actor);
        
        virtual std::set<std::string> & directions() = 0;
        virtual Place & neighbor(std::string direction) = 0;
        
        std::string description();
        
        virtual void save(std::ostream & os);
        
        // TODO pick_up / drop item
        
    protected:
        Controller & controller;
        const std::string name, description_text;
        std::set<Actor*> actors;
        
        bool has_nonplayer_actors();
};

}

#endif



