#include "wolf.h"
#include "controller.h"
#include "place.h"
#include "woods.h"

#include <string>
#include <set>

namespace game {

Wolf::Wolf(Controller & c, Place & p) :
    Actor(c, p, 100, 40)
{

}

Wolf::Wolf(Controller & c, Place & p, unsigned int h, unsigned int damage) :
    Actor(c, p, h, damage)
{

}

Wolf::~Wolf()
{

}

/**
 * Wolf::act
 *
 * Tries to move around randomly, can only move in the woods
 */
void Wolf::act()
{
    Place * place = get_place();
    if (place != 0) {
        std::set<std::string> directions = place->directions();
        std::set<std::string> copy_directions = directions;

        while (!copy_directions.empty()) {
            int index = (int) (rand() % copy_directions.size());
            auto iterator = copy_directions.begin();
            advance(iterator, index);

            Place & place = get_place()->neighbor(*iterator);
            if (dynamic_cast<Woods*>(&place) != 0) {
                go(*iterator);
                break;
            } else {
                copy_directions.erase(iterator);
            }
        }
    }
}

std::string Wolf::type() const
{
    return "wolf";
}

std::string Wolf::name() const
{
    return "Wolfy";
}

std::string Wolf::description() const
{
    return "The kid looks at the wolf, the wolf looks back...";
}

}


