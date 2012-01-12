#include "player.h"
#include "controller.h"
#include <string>

namespace game {

Player::Player(Controller & c, Place & p) :
    Human(c, p)
{
    controller.set_player(*this);
}

Player::Player(Controller & c, Place & p, unsigned int h, unsigned int damage) :
    Human(c, p, h, damage)
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
