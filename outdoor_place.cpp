#include <stdexcept>

#include "outdoor_place.h"
#include "actor.h"
#include "controller.h"


namespace game {

static const char *direction_names[] = {
    "N", "NE", "E", "SE", "S", "SW", "W", "NW"
};

OutdoorPlace::OutdoorPlace(Controller & controller_,
                           std::string name_, std::string description_text_,
                           size_t x_, size_t y_,
                           OutdoorPlace::Direction allowed_) :
    Place(controller_, name_, description_text_),
    x(x_),
    y(y_),
    allowed(allowed_)
{
}

OutdoorPlace::~OutdoorPlace()
{
}

std::set<std::string> & OutdoorPlace::directions()
{
    std::set<std::string> & set = *new std::set<std::string>();
    
    for (size_t dir = 0; dir < 8; dir++) {
        if ((1 << dir) & allowed) {
            set.insert(direction_names[dir]);
        }
    }
    
    return set;
}

Place & OutdoorPlace::neighbor(std::string direction)
{
    for (size_t dir = 0; dir < 8; dir++) {
        if (direction == direction_names[dir]) {
            return neighbor(static_cast<Direction>(dir));
        }
    }
    
    throw new std::invalid_argument("invalid direction name");
}

Place & OutdoorPlace::neighbor(OutdoorPlace::Direction dir)
{
    static const struct { int x, y; } offset[] = {
        /*N*/{  0, -1 }, /*NE*/{  1, -1 }, /*E*/{  1,  0 }, /*SE*/{  1,  1 },
        /*S*/{  0,  1 }, /*SW*/{ -1,  1 }, /*W*/{ -1,  0 }, /*NW*/{ -1, -1 }
    };
    
    return controller.get_room(offset[dir].x, offset[dir].y);
}


}


