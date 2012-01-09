#include "controller.h"
#include "actor.h"
#include "place.h"
#include "backpack.h"
#include "key.h"
#include "player.h"

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

    Player * player = new Player(*this);
    Backpack * bp = new Backpack(*this);
    Key * key = new Key(*this);
    //bp->add(*key);

    player->pick_up(*key);
    player->drop(*key);
}


}


