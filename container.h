#ifndef CONTAINER_H
#define CONTAINER_H

#include "types.h"
#include "object.h"
#include <string>
#include <set>

namespace game {

class Container : public Object {
    
    public:
        Container(Controller &c);
        virtual ~Container() = 0;

        virtual int hold_weight() const = 0;
        virtual int hold_volume() const = 0;
        virtual bool add(Object &);
        virtual bool remove(Object &);
        virtual bool contains(std::string) const;

    protected:
        std::set<Object *> objects;
        Controller &controller;

        int used_weight;
        int used_volume;
};

}

#endif
