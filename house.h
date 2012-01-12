#ifndef HOUSE_H
#define HOUSE_H

#include <set>
#include <string>
#include "outdoor_place.h"

namespace game {

class House : public OutdoorPlace {

    public:

        House(Controller &, std::string, std::string, size_t, size_t, DirectionSet);
        virtual ~House();

        virtual std::set<std::string> directions() const;
        virtual Place & neighbor(std::string) const;

        virtual std::string type() const;
};

}

#endif



