#include "firewood.h"
#include "controller.h"

namespace game {

Firewood::Firewood(Controller &c) :
    Object(c),
    controller(c)
{
    
}

Firewood::~Firewood()
{

}

int Firewood::weight() const
{
    return 20;
}

int Firewood::volume() const
{
    return 80;
}

int Firewood::price() const
{
    return 10;
}

std::string Firewood::name() const
{
    return "firewood";
}

std::string Firewood::type() const
{
    return "firewood";
}

std::string Firewood::description() const
{
    return "Some firewood";
}


}


