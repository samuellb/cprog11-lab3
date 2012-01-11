#ifndef WOODS_H
#define WOODS_H

#include <set>
#include <string>
#include "outdoor_place.h"

namespace game {

class Woods : public OutdoorPlace {
    
    public:
        
        Woods(Controller &, std::string, std::string, size_t, size_t, DirectionSet);
        virtual ~Woods();
        
    private:
        void chop(Actor & actor);
};

}

#endif



