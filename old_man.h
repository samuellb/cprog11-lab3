#ifndef OLD_MAN_H
#define OLD_MAN_H

#include "types.h"
#include "human.h"
#include <string>

namespace game {

class OldMan : public Human {
    
    public:
        OldMan(Controller &, Place &);
        OldMan(Controller &, Place &, unsigned int, unsigned int);
        virtual ~OldMan();

        virtual void talked_to(Actor &);
        virtual void act();

        virtual std::string type() const;
        virtual std::string name() const;
        virtual std::string description() const;
        
    private:
        bool is_freezing() const;
};

}

#endif



