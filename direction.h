#ifndef DIRECTION_H
#define DIRECTION_H

#include <bitset>

namespace game {

enum Direction { N, E, S, W };

Direction parse_direction(char);
Direction parse_direction(std::string);
extern const char *direction_names[];

class DirectionSet {
    public:
        DirectionSet(std::string);
        bool operator[](Direction) const;
        bool operator[](unsigned int) const;
    private:
        std::bitset<4> bits;
        static unsigned long parse(std::string);
};

}

#endif

