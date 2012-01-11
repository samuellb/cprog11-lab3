#ifndef SWORD_H
#define SWORD_H

#include "types.h"
#include "weapon.h"
#include <string>

namespace game {

class Sword : public Weapon {
    
    public:
        Sword(Controller &);
        virtual ~Sword();

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
