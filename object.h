#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"
#include <string>

namespace game {

class Object {
    
    public:
        Object(Controller &c);
        virtual ~Object() = 0;

        virtual int weight() const = 0;
        virtual int volume() const = 0;
        virtual int price() const = 0;

        virtual std::string name() const = 0;
        virtual std::string type() const = 0;
        virtual std::string description() const = 0;

    protected:
        Controller &controller;
};

}

#endif



