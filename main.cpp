#include <stdexcept>

#include "controller.h"

int main() {
    game::Controller controller;
    controller.load("maps/map.txt");
    controller.run_step();

    return 0;
}


