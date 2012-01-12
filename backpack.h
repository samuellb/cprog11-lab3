#ifndef BACKPACK_H
#define BACKPACK_H

#include "types.h"
#include "container.h"
#include <string>

namespace game {

class Backpack : public Container {
    
    public:
        Backpack(Controller &, std::string);
        virtual ~Backpack();

        virtual int weight() const;
        virtual int volume() const;
        virtual int price() const;

        virtual int hold_weight() const;
        virtual int hold_volume() const;
        //virtual bool add(Object &);
        //virtual bool remove(Object &);

        virtual std::string type() const;
        virtual std::string description() const;
};

}

#endif
