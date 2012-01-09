#include "key.h"
#include "controller.h"

namespace game {

Key::Key(Controller &c) :
    Object(c),
    controller(c)
{
    
}

Key::~Key()
{

}

int Key::weight()
{
    return 1;
}

int Key::volume()
{
    return 1;
}

int Key::price()
{
    return 100;
}

std::string Key::name()
{
    return "Key";
}

std::string Key::type()
{
    return "Key";
}

std::string Key::description()
{
    return "Something something....";
}


}
