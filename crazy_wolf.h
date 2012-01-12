#ifndef CRAZY_WOLF_H
#define CRAZY_WOLF_H

#include "types.h"
#include "wolf.h"
#include <string>

namespace game {

class CrazyWolf : public Wolf {
    
    public:
        CrazyWolf(Controller &, Place &);
        CrazyWolf(Controller &, Place &, unsigned int, unsigned int);
        virtual ~CrazyWolf();

        virtual void act();

        virtual std::string type() const;
        virtual std::string name() const;
        virtual std::string description() const;
};

}

#endif
