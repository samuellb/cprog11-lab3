#ifndef KEY_H
#define KEY_H

#include "types.h"
#include "object.h"
#include <string>

namespace game {

class Key : public Object {
    
    public:
        Key(Controller &, std::string);
        ~Key();

        virtual int weight() const;
        virtual int volume() const;
        virtual int price() const;

        virtual std::string type() const;
        virtual std::string description() const;
};

}

#endif



