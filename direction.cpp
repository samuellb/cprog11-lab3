#include <stdexcept>
#include <cctype>
#include <string>

#include "direction.h"

namespace game {

const char *direction_names[] = {
    "north", "east", "south", "west"
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
    if (s.size() < 1) throw std::invalid_argument("direction must be 1 character long");
    else return parse_direction(s[0]);
}

DirectionSet::DirectionSet(std::string allowed_str) :
    bits(parse(allowed_str)) { }

unsigned long DirectionSet::parse(std::string s)
{
    unsigned long allowed = 0;
    
    if (s != "-") {
        for (char c : s) {
            allowed |= 1 << static_cast<unsigned long>(parse_direction(c));
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

std::string DirectionSet::to_string() const
{
    std::string s;
    if ((*this)[Direction::N]) s += "n";
    if ((*this)[Direction::E]) s += "e";
    if ((*this)[Direction::S]) s += "s";
    if ((*this)[Direction::W]) s += "w";
    
    if (s.empty()) s = "-";
    
    return s;
}

}


