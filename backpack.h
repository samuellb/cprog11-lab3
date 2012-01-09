#ifndef BACKPACK_H
#define BACKPACK_H

#include "types.h"
#include "container.h"
#include <string>

namespace game {

class Backpack : public Container {
    
    public:
        Backpack(Controller &c);
        virtual ~Backpack();

        virtual int weight();
        virtual int volume();
        virtual int price();

        virtual int hold_weight();
        virtual int hold_volume();
        //virtual bool add(Object &);
        //virtual bool remove(Object &);

        virtual std::string name() const;
        virtual std::string type() const;
        virtual std::string description() const;

    protected:
        Controller &controller;
};

}

#endif
