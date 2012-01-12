#include <stdexcept>

#include "outdoor_place.h"
#include "actor.h"
#include "controller.h"


namespace game {

OutdoorPlace::OutdoorPlace(Controller & controller,
                           std::string name, std::string description,
                           size_t x_, size_t y_,
                           DirectionSet allowed_) :
    Place(controller, name, description),
    x(x_),
    y(y_),
    allowed(allowed_)
{
}

OutdoorPlace::~OutdoorPlace()
{
}

std::set<std::string> OutdoorPlace::directions() const
{
    std::set<std::string> set;
    
    for (size_t dir = 0; dir < 4; dir++) {
        if (allowed[dir]) {
            set.insert(direction_names[dir]);
        }
    }
    
    return set;
}

Place & OutdoorPlace::neighbor(std::string direction) const
{
    return neighbor(parse_direction(direction));
}

Place & OutdoorPlace::neighbor(Direction dir) const
{
    static const struct { int x, y; } offset[] = {
        /*N*/{  0, -1 }, /*E*/{  1,  0 }, /*S*/{  0,  1 }, /*W*/{ -1,  0 }
    };
    
    return controller.get_place(x + offset[dir].x, y + offset[dir].y);
}

std::string OutdoorPlace::type() const
{
    return "outdoor";
}

void OutdoorPlace::save_properties(std::ostream & os) const
{
    os << x << " " << y << " " << allowed.to_string();
}


}


