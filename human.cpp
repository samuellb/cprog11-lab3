#include "human.h"
#include "controller.h"

namespace game {

Human::Human(Controller &c) :
    Actor(c),
    controller(c)
{
    
}

void Human::go()
{
    // move
}

}


