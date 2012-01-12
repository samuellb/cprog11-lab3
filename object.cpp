#include <sstream>
#include "object.h"
#include "controller.h"

namespace game {

Object::Object(Controller &c, std::string n) :
    controller(c),
    name_(n)
{
    
}

Object::~Object()
{

}

std::string Object::name() const
{
    return name_;
}

void Object::save(std::ostream & os, std::string & reference_type, std::string & reference) const
{
    os << type() << " \"" << name() << "\" " << reference_type << " \"" << reference << "\"" << std::endl;
}

}
