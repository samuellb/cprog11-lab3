#include "crazy_wolf.h"
#include "controller.h"
#include "place.h"
#include "woods.h"

#include <string>
#include <set>

namespace game {

CrazyWolf::CrazyWolf(Controller & c, Place & p) :
    Wolf(c, p, 100, 49)
{
    std::cout << "The kid hears something in the woods, it sounds like a crazy wolf spawned a few clicks from here." << std::endl;
}

CrazyWolf::CrazyWolf(Controller & c, Place & p, unsigned int h, unsigned int damage) :
    Wolf(c, p, h, damage)
{
}

CrazyWolf::~CrazyWolf()
{

}

/**
 * CrazyWolf::act
 *
 * Tries to attack any human at this place, then move around.
 */
void CrazyWolf::act()
{
    Place * place = get_place();
    if (place != 0) {
        Actor * player = place->get_actor("kid");
        if (player != 0) {
            if (fight(*player) == false) {
                return;
            }
        }
    }

    Wolf::act();
}

std::string CrazyWolf::type() const
{
    return "crazy_wolf";
}

std::string CrazyWolf::name() const
{
    return "crazy";
}

std::string CrazyWolf::description() const
{
    return "A really crazy wolf that attacks any human.";
}

}


