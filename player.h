#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "human.h"
#include <string>

namespace game {

class Player : public Human {
    
    public:
        Player(Controller &c);
        virtual ~Player();

        virtual void act();
        virtual void talk(Actor &);
        virtual void fight(Actor &);

        virtual std::string name();
        virtual std::string description();
    protected:
        Controller &controller;
};

}

#endif



