#include <stdexcept>

#include "house.h"
#include "actor.h"
#include "controller.h"

namespace game {

House::House(Controller & controller,
            std::string name, std::string description,
            size_t x, size_t y, DirectionSet allowed) :
    OutdoorPlace(controller, name, description, x, y, allowed)
{
}

House::~House()
{
}

std::string House::type() const
{
    return "trap";
}

std::set<std::string> House::directions() const
{
    return std::set<std::string>{"out"};
}

Place & House::neighbor(std::string dir) const
{
    if (dir == "out") {
        auto realdir = OutdoorPlace::directions();
        return OutdoorPlace::neighbor(*realdir.begin());
    } else {
        throw std::invalid_argument("only 'out' is allowed");
    }
}



}


