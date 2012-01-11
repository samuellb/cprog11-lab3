#ifndef CONTOLLER_H
#define CONTOLLER_H

#include <vector>
#include <map>
#include <iostream>
#include "types.h"
#include "map.h"

namespace game {

class Controller {
    
    public:
        Controller();
        ~Controller();
        
        void run_step();
        void load(std::string);

        void add_place(Place &);
        
        const Place & get_place(std::string) const;
        inline Place & get_place(std::string name)
        {
            return const_cast<Place&>(const_cast<const Controller*>(this)->get_place(name));
        }
        
        const Place & get_place(size_t x, size_t y) const;
        inline Place & get_place(size_t x, size_t y)
        {
            return const_cast<Place&>(const_cast<const Controller*>(this)->get_place(x, y));
        }
        
    private:
        Map map;
        std::vector<Actor*> actors;
};

}

#endif



