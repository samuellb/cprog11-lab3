#include "object.h"
#include "controller.h"

namespace game {

Object::Object(Controller &c) :
    controller(c)
{
    
}

Object::~Object()
{

}

void Object::save(std::ostream & os, std::string & reference_type, std::string & reference) const
{
    os << type() << " \"" << name() << "\" " << reference_type << " \"" << reference << "\"" << std::endl;
}

}
