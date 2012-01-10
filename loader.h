#ifndef LOADER_H
#define LOADER_H

#include <vector>
#include <map>
#include <iostream>
#include "types.h"
#include "map.h"

namespace game {

class Loader {
    
    public:
        Loader(Controller &);
        ~Loader();
        
        void load(std::istream & is);
        
    private:
        typedef void (Controller::*parse_method_type)(std::istream & is);
        std::map<std::string, parse_method_type> parse_methods;
        
        void parse_outdoor(std::istream &);
        //void parse_player(std::istream &);

        Controller &controller;
};

}

#endif
