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

void Player::talk(Actor & actor)
{
    std::cout << "the player cannot talk, " << actor.name() << " says something" << std::endl;
}

std::string Player::name()
{
    return "kid";
}

std::string Player::description()
{
    return "The main character of the story";
}

}
