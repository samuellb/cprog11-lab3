#include "firewood.h"
#include "controller.h"

namespace game {

Firewood::Firewood(Controller &c, std::string n) :
    Object(c, n)
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
    return 40;
}

int Firewood::price() const
{
    return 10;
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


