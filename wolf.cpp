#include "wolf.h"
#include "controller.h"

namespace game {

Wolf::Wolf(Controller &c) :
    Actor(c),
    controller(c)
{
    
}

Wolf::~Wolf()
{

}

void Wolf::go()
{
    // move
}

}


