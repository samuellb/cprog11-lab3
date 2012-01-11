#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "human.h"
#include <string>

namespace game {

class Player : public Human {
    
    public:
        Player(Controller &, Place &);
        virtual ~Player();

        virtual void act();
        virtual void talk(Actor &);

        virtual std::string type() const;
        virtual std::string name() const;
        virtual std::string description() const;
        virtual bool is_player() const;
    protected:
        Controller &controller;
};

}

#endif



