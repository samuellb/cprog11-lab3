#include "player.h"
#include "controller.h"
#include <string>

namespace game {

Player::Player(Controller & c, Place & p) :
    Human(c, p)
{
    controller.set_player(*this);
}

Player::~Player()
{

}

bool Player::is_player() const
{
    return true;
}


void Player::act()
{
}

void Player::talk(Actor & actor)
{
    std::cout << "the player cannot talk, " << actor.name() << " says something" << std::endl;
}

std::string Player::type() const
{
    return "player";
}

std::string Player::name() const
{
    return "kid";
}

std::string Player::description() const
{
    return "The main character of the story";
}

}
