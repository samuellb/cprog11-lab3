#ifndef KEY_H
#define KEY_H

#include "types.h"
#include "object.h"
#include <string>

namespace game {

class Key : public Object {
    
    public:
        Key(Controller &c);
        ~Key();

        virtual int weight();
        virtual int volume();
        virtual int price();

        virtual std::string name();
        virtual std::string type();
        virtual std::string description();

    protected:
        Controller &controller;
};

}

#endif



