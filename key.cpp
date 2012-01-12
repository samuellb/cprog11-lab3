#include "key.h"
#include "controller.h"

namespace game {

Key::Key(Controller &c, std::string n) :
    Object(c, n)
{
    
}

Key::~Key()
{

}

int Key::weight() const
{
    return 1;
}

int Key::volume() const
{
    return 1;
}

int Key::price() const
{
    return 100;
}

std::string Key::type() const
{
    return "key";
}

std::string Key::description() const
{
    return "Something something....";
}


}
