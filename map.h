#ifndef MAP_H
#define MAP_H

#include <cstddef>
#include <set>
#include <vector>
#include "types.h"

namespace game {

class Map {
    
    public:
        Map(size_t w, size_t h);
        ~Map();
        
        Place & get(size_t x, size_t y);
        void set(size_t x, size_t y, Place & place);
        void add(Place & place);
        
    private:
        size_t width, height;
        std::vector<Place*> grid;
        std::set<Place*> places;
        
        void check_inside(size_t x, size_t y);
        
        // disable copy and assignment
        Map & operator=(const Map &);
        Map(const Map &);
};

}

#endif



