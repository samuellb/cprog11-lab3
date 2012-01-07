#include "walking_actor.h"
#include "controller.h"

namespace game {

WalkingActor::WalkingActor(Controller &c) :
    Actor(c),
    controller(c)
{
    
}

}


