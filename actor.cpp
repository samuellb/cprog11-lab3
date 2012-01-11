#include "actor.h"
#include "place.h"
#include "controller.h"
#include "weapon.h"

namespace game {

Actor::Actor(Controller &c, Place &p, int damage) :
    health(100),
    base_damage(damage),
    current_place(&p),
    current_weapon(0),
    controller(c)
{
}

Actor::~Actor()
{
}

void Actor::go(std::string direction)
{
    Place & new_place = current_place->neighbor(direction);
    current_place->leave(*this);
    new_place.enter(*this);
    current_place = &new_place;
}

void Actor::talk(Actor & actor)
{

}

void Actor::fight(Actor & actor)
{
    int damage = base_damage;
    if (current_weapon != 0) {
        damage += current_weapon->get_damage();
    }

    int opponent_damage = actor.base_damage;
    if (actor.current_weapon != 0) {
        opponent_damage = actor.current_weapon->get_damage();
    }

    std::cout << name() << " initiated a fight with " << actor.name() << " to the death." << std::endl;

    while (is_alive() || actor.is_alive()) {
        if (current_weapon != 0) {
            std::cout << "  " << name() << " hits " << actor.name() << " with " << current_weapon->name() << " for " << damage << " health points" << std::endl;
        } else {
            std::cout << "  " << name() << " hits " << actor.name() << " for " << damage << " health points" << std::endl;
        }

        actor.health -= damage;

        if (!actor.is_alive()) {
            std::cout << name() << " won this fight, " << actor.name() << " is dead." << std::endl;
            controller.kill(actor);
            return;
        }

        if (actor.current_weapon != 0) {
            std::cout << "  " << actor.name() << " hits " << name() << " with " << actor.current_weapon->name() << " for " << opponent_damage << " health points" << std::endl;
        } else {
            std::cout << "  " << actor.name() << " hits " << name() << " for " << opponent_damage << " health points" << std::endl;
        }

        health -= opponent_damage;

        if (!is_alive()) {
            std::cout << actor.name() << " won this fight, " << name() << " is dead." << std::endl;
            controller.kill(*this);
            return;
        }
    }
}

bool Actor::drop(Object &)
{
    return false;
}

bool Actor::pick_up(Object &)
{
    return false;
}

bool Actor::is_player()
{
    return false;
}

Place & Actor::place()
{
    return *current_place;
}

void Actor::save(std::ostream & os) const
{
    os << type() << " " << current_place->name() << std::endl;
}


}


