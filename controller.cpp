#include "controller.h"
#include "actor.h"

namespace game {

Controller::Controller() :
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


