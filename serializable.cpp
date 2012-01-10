#include "serializable.h"

namespace game {

void Serializable::save(std::ostream & os) const
{
    os << type();
}


}


