#include <stdexcept>

#include "map.h"
#include "place.h"

namespace game {

Map::Map(size_t w, size_t h) :
    width(w),
    height(h),
    grid(w*h),
    places()
{
}

Map::~Map()
{
    for (auto place : places) {
        delete place;
    }
}

Place & Map::get(size_t x, size_t y)
{
    check_inside(x, y);
    
    if (grid[x*width + y] == NULL) {
        throw std::logic_error("tried to get non-existent place");
    }
    
    return *grid[x*width + y];
}

void Map::set(size_t x, size_t y, Place & place)
{
    check_inside(x, y);
    
    if (grid[x*width + y] != NULL) {
        throw std::logic_error("duplicate places at the same coordinates");
    }
    
    add(place);
    grid[x*width + y] = &place;
}

void Map::add(Place & place)
{
    places.insert(&place);
}

void Map::check_inside(size_t x, size_t y)
{
    if (x >= width || y >= height) {
        throw std::out_of_range("map coordinate is out of range");
    }
}


}


