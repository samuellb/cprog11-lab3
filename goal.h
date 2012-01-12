#ifndef GOAL_H
#define GOAL_H

#include <set>
#include <string>
#include "outdoor_place.h"

namespace game {

class Goal : public OutdoorPlace {
    
    public:
        
        Goal(Controller &, std::string, std::string, size_t, size_t, DirectionSet);
        virtual ~Goal();
        
        virtual std::string type() const;
        virtual void enter(Actor &);

};

}

#endif



