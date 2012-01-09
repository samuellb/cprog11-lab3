#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"
#include <string>

namespace game {

class Object {
    
    public:
        Object(Controller &c);
        virtual ~Object() = 0;

        virtual int weight() = 0;
        virtual int volume() = 0;
        virtual int price() = 0;

        virtual std::string name() = 0;
        virtual std::string type() = 0;
        virtual std::string description() = 0;

    protected:
        Controller &controller;
};

}

#endif



