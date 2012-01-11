#ifndef OLD_MAN_H
#define OLD_MAN_H

#include "types.h"
#include "human.h"
#include <string>

namespace game {

class OldMan : public Human {
    
    public:
        OldMan(Controller &, Place &);
        virtual ~OldMan();

        virtual void act();

        virtual std::string type() const;
        virtual std::string name() const;
        virtual std::string description() const;
    protected:
        Controller &controller;
};

}

#endif



