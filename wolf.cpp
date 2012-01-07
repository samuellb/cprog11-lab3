#include "wolf.h"
#include "controller.h"

namespace game {

Wolf::Wolf(Controller &c) :
    Actor(c),
    controller(c)
{
    
}

void Wolf::go()
{
    // move
}

}


