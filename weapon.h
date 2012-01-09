#ifndef WEAPON_H
#define WEAPON_H

#include "types.h"
#include "object.h"
#include <string>

namespace game {

class Weapon : public Object {
    
    public:
        Weapon(Controller &c, unsigned int);
        virtual ~Weapon();

        virtual int weight() = 0;
        virtual int volume() = 0;
        virtual int price() = 0;

        virtual std::string name() const = 0;
        virtual std::string type() const;
        virtual std::string description() const = 0;

    protected:
        unsigned int damage;

        Controller &controller;
};

}

#endif

