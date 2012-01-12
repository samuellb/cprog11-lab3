#include "sword.h"
#include "controller.h"

#include <sstream>
#include <string>

namespace game {
    
Sword::Sword(Controller &c, std::string n) :
    Weapon(c, n, 25)
{
    
}

Sword::~Sword()
{

}

int Sword::weight() const
{
    return 13;
}

int Sword::volume() const
{
    return 10;
}

int Sword::price() const
{
    return 140;
}

std::string Sword::type() const
{
    return "sword";
}

std::string Sword::description() const
{
    std::stringstream out;
    out << get_damage();
    return "A plain sword (" + out.str() + " damage per hit)";
}

}
