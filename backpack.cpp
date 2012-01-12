#include "backpack.h"
#include "controller.h"
#include <string>

namespace game {

Backpack::Backpack(Controller &c, std::string n) :
    Container(c, n)
{

}

Backpack::~Backpack()
{

}

int Backpack::weight() const
{
    return 3;
}

int Backpack::volume() const
{
    return used_volume;
}

int Backpack::price() const
{
    return 1;
}


int Backpack::hold_weight() const
{
    return 100;
}

int Backpack::hold_volume() const
{
    return 100;
}

std::string Backpack::type() const
{
    return "backpack";
}

std::string Backpack::description() const
{
    return "A magic backpack created by God.";
}

}
