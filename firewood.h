#ifndef FIREWOOD_H
#define FIREWOOD_H

#include "types.h"
#include "object.h"
#include <string>

namespace game {

class Firewood : public Object {
    
    public:
        Firewood(Controller &c);
        ~Firewood();

        virtual int weight() const;
        virtual int volume() const;
        virtual int price() const;

        virtual std::string name() const;
        virtual std::string type() const;
        virtual std::string description() const;

    protected:
        Controller &controller;
};

}

#endif



