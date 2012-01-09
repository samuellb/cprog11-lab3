#ifndef OUTDOOR_PLACE_H
#define OUTDOOR_PLACE_H

#include <set>
#include <string>
#include "types.h"
#include "place.h"

namespace game {

class OutdoorPlace : Place {
    
    public:
        
        enum Direction { N, NE, E, SE, S, SW, W, NW };
        
        OutdoorPlace(Controller & controller_,
                     std::string name_, std::string description_text_,
                     size_t x_, size_t y_, Direction allowed_);
        virtual ~OutdoorPlace();
        
        virtual std::set<std::string> & directions();
        virtual Place *neighbor(std::string direction);
        Place *neighbor(Direction direction);
        
        // TODO pick_up / drop item
        
    private:
        const size_t x, y;
        const Direction allowed;
};

}

#endif



