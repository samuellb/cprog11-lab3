#ifndef OUTDOOR_PLACE_H
#define OUTDOOR_PLACE_H

#include <set>
#include <string>
#include "types.h"
#include "place.h"

namespace game {

class OutdoorPlace : public Place {
    
    public:
        
        enum Direction { N, E, S, W };
        
        OutdoorPlace(Controller & controller_,
                     std::string name_, std::string description_text_,
                     size_t x_, size_t y_, Direction allowed_);
        virtual ~OutdoorPlace();
        
        virtual std::set<std::string> & directions() const;
        virtual Place & neighbor(std::string direction) const;
        Place & neighbor(Direction direction) const;
        Direction parse_direction(std::string direction) const;
        
        // TODO pick_up / drop item
        
    private:
        const size_t x, y;
        const Direction allowed;
};

}

#endif



