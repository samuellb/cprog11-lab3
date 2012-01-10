#include <iostream>
#include <fstream>
#include <stdexcept>

#include "controller.h"

int main() {
    
    game::Controller c;
    std::ifstream mapfile("maps/map.txt");
    
    c.load(mapfile);
    c.run_step();
    
    
    return 0;
}


