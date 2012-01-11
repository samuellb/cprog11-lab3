#ifndef ACTOR_H
#define ACTOR_H

#include "types.h"
#include <ostream>
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

        virtual std::string name() const = 0;
        virtual std::string type() const = 0;
        virtual std::string description() const = 0;
        virtual bool is_player();

        inline bool is_alive() { return health > 0; }
        inline Weapon * get_weapon() { return current_weapon; }
        inline void set_weapon(Weapon * weapon) { current_weapon = weapon; }
        
        Place & place();

        int health;
        int base_damage;
        
        virtual void save(std::ostream & is) const;
        
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



