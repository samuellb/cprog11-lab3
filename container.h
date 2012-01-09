#ifndef CONTAINER_H
#define CONTAINER_H

#include "types.h"
#include "object.h"
#include <string>
#include <vector>

namespace game {

class Container : public Object {
    
    public:
        Container(Controller &c);
        virtual ~Container() = 0;

        virtual int hold_weight() = 0;
        virtual int hold_volume() = 0;
        virtual bool add(Object &);
        virtual bool remove(Object &);

        std::vector<Object *> * objects;

    protected:
        Controller &controller;

        int used_weight;
        int used_volume;
};

}

#endif
