#include "controller.h"
#include "actor.h"
#include "place.h"
#include "backpack.h"
#include "key.h"

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

    Backpack * bp = new Backpack(*this);
    Key * key = new Key(*this);
    bp->add(*key);
}


}


