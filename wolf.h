#ifndef WOLF_H
#define WOLF_H

#include "types.h"
#include "actor.h"
#include <string>

namespace game {

class Wolf : public Actor {
    
    public:
        Wolf(Controller &, Place &);
        virtual ~Wolf();

        virtual void act();

        virtual std::string type() const;
        virtual std::string name() const;
        virtual std::string description() const;
};

}

#endif
