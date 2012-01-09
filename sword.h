#ifndef SWORD_H
#define SWORD_H

#include "types.h"
#include "weapon.h"
#include <string>

namespace game {

class Sword : public Weapon {
    
    public:
        Sword(Controller &c, unsigned int);
        virtual ~Sword();

        virtual int weight();
        virtual int volume();
        virtual int price();

        virtual std::string name() const;
        virtual std::string type() const;
        virtual std::string description() const;

    protected:
        Controller &controller;
};

}

#endif
