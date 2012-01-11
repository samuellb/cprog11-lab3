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
    for (auto keyvalue : places) {
        delete keyvalue.second;
    }
}

const Place & Map::get(size_t x, size_t y) const
{
    check_inside(x, y);
    
    if (grid[x*width + y] == NULL) {
        throw std::logic_error("tried to get non-existent place");
    }
    
    return *grid[x*width + y];
}

const Place & Map::get(std::string name) const
{
    return *const_cast<Map*>(this)->places[name];
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
    places.insert(std::make_pair(place.name(), &place));
}

void Map::check_inside(size_t x, size_t y) const
{
    if (x >= width || y >= height) {
        throw std::out_of_range("map coordinate is out of range");
    }
}

void Map::save(std::ostream & os) const
{
    for (auto it : places) {
        it.second->save(os);
    }
}


}


