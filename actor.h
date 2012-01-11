#ifndef ACTOR_H
#define ACTOR_H

#include "types.h"
#include <string>

namespace game {

class Actor {
    
    public:
        Actor(Controller &, Place &, int);
        virtual ~Actor();

        virtual void act() = 0;
        virtual void go(std::string);
        virtual void talk(Actor &);
        virtual void fight(Actor &);
        virtual bool drop(Object &);
        virtual bool pick_up(Object &);

        virtual std::string name() = 0;
        virtual std::string type() = 0;
        virtual std::string description() = 0;
        virtual bool is_player();

        inline bool is_alive() { return health > 0; }
        inline Weapon * get_weapon() { return current_weapon; }
        
        Place & place();

        int health;
        int base_damage;
        
    protected:
        Place * current_place;
        Weapon * current_weapon;
        Controller &controller;
        
    private:
        // disable copy and assignment
        Actor(const Actor &);
        Actor & operator=(const Actor &);
};

}

#endif



