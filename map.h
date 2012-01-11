#ifndef MAP_H
#define MAP_H

#include <cstddef>
#include <ostream>
#include <map>
#include <vector>
#include "types.h"

namespace game {

class Map {
    
    public:
        Map(size_t w, size_t h);
        ~Map();
        
        const Place & get(size_t x, size_t y) const;
        inline Place & get(size_t x, size_t y)
        {
            return const_cast<Place&>(const_cast<const Map*>(this)->get(x, y));
        }
        
        const Place & get(std::string name) const;
        inline Place & get(std::string name)
        {
            return const_cast<Place&>(const_cast<const Map*>(this)->get(name));
        }
        
        void set(size_t x, size_t y, Place & place);
        void add(Place & place);
        
        void save(std::ostream & os) const;
        
    private:
        size_t width, height;
        std::vector<Place*> grid;
        std::map<std::string, Place*> places;
        
        void check_inside(size_t x, size_t y) const;
        
        // disable copy and assignment
        Map & operator=(const Map &);
        Map(const Map &);
};

}

#endif



