#include <stdexcept>
#include <ctime>
#include <cstdlib>

#include "controller.h"

int main() {
    std::srand(std::time(NULL));
    
    game::Controller controller;
    controller.run_game();

    return 0;
}


