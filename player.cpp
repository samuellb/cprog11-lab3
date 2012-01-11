#include "player.h"
#include "controller.h"
#include <string>

namespace game {

Player::Player(Controller & c, Place & p) :
    Human(c, p),
    controller(c)
{
    controller.set_player(*this);
}

Player::~Player()
{

}

bool Player::is_player()
{
    return true;
}


void Player::act()
{
}

void Player::fight(Actor & actor)
{
}

void Player::talk(Actor & actor)
{
}

std::string Player::name()
{
    return "The kid";
}

std::string Player::description()
{
    return "The main character of the story";
}

}
