#ifndef WEAPON_H
#define WEAPON_H

#include "types.h"
#include "object.h"
#include <string>

namespace game {

class Weapon : public Object {
    
    public:
        Weapon(Controller &, int);
        virtual ~Weapon();

        virtual int weight() const = 0;
        virtual int volume() const = 0;
        virtual int price() const = 0;

        virtual std::string name() const = 0;
        virtual std::string type() const = 0;
        virtual std::string description() const = 0;

        inline int get_damage() const { return damage; }

    protected:
        unsigned int damage;

        Controller &controller;
};

}

#endif

