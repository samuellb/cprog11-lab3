#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>
#include <string>
#include "types.h"

namespace game {

struct Serializable {
    virtual std::string type() const = 0;
    virtual void save(std::ostream &) const;
};

/*template<const char *const TN> class SerializableMixIn {
    virtual std::string type() const {
        return TN;
    }
    
    static std::string static_type() {
        return TN;
    }
};*/

}

#endif



