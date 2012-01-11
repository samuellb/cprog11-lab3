#ifndef PORTAL_H
#define PORTAL_H

#include <set>
#include <string>
#include "outdoor_place.h"

namespace game {

class Portal : public OutdoorPlace {
    
    public:
        
        Portal(Controller &, std::string, std::string, size_t, size_t, DirectionSet);
        virtual ~Portal();
        
        virtual std::string type() const;
        
    private:
        void portal(Actor & actor); // use portal
};

}

#endif



