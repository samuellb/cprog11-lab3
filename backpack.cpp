#include "backpack.h"
#include "controller.h"
#include <string>

namespace game {

Backpack::Backpack(Controller &c) :
    Container(c),
    controller(c)
{

}

Backpack::~Backpack()
{

}

int Backpack::weight()
{
    return 3;
}

int Backpack::volume()
{
    return used_volume;
}

int Backpack::price()
{
    return 1;
}


int Backpack::hold_weight()
{
    return 100;
}

int Backpack::hold_volume()
{
    return 100;
}

std::string Backpack::name() const
{
    return "Backpack";
}

std::string Backpack::type() const
{
    return "Container";
}

std::string Backpack::description() const
{
    return "A magic backpack created by God.";
}

}
