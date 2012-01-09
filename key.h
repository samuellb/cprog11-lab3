#ifndef KEY_H
#define KEY_H

#include "types.h"
#include "object.h"
#include <string>

namespace game {

class Key : public Object {
    
    public:
        Key(Controller &c);
        ~Key();

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



