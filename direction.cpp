#include <stdexcept>
#include <cctype>

#include "direction.h"

namespace game {

const char *direction_names[] = {
    "N", "E", "S", "W"
};

Direction parse_direction(char c)
{
    c = std::tolower(c);
    switch (c) {
        case 'n': return Direction::N;
        case 'e': return Direction::E;
        case 's': return Direction::S;
        case 'w': return Direction::W;
    }
    throw std::invalid_argument("invalid direction");
}

Direction parse_direction(std::string s)
{
    if (s.size() != 1) throw std::invalid_argument("direction must be 1 character long");
    else return parse_direction(s[0]);
}

DirectionSet::DirectionSet(std::string allowed_str) :
    bits(parse(allowed_str)) { }

unsigned long DirectionSet::parse(std::string s)
{
    unsigned long allowed = 0;
    
    if (s != "-") {
        for (char c : s) {
            allowed |= static_cast<unsigned long>(parse_direction(c));
        }
    }
    return allowed;
}

bool DirectionSet::operator[](Direction dir) const
{
    return bits[static_cast<unsigned>(dir)];
}

bool DirectionSet::operator[](unsigned int dir) const
{
    return bits[dir];
}

}


