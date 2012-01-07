#include "controller.h"
#include "actor.h"
#include "place.h"

namespace game {

Controller::Controller() :
    map(10, 10),
    actors()
{
}
        
void Controller::run_step()
{
    for (auto actor : actors) {
        actor->act();
    }
}


}


