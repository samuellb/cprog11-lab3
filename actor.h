#ifndef ACTOR_H
#define ACTOR_H

#include "types.h"
#include "container.h"

#include <ostream>
#include <string>
#include <iostream>

namespace game {

class Actor {
    
    public:
        Actor(Controller &, Place &, int);
        virtual ~Actor();

        virtual void act() = 0;
        void go(std::string);
        void teleport(std::string);
        void talk(Actor &);
        virtual void talked_to(Actor &);
        virtual void fight(Actor &);
        virtual bool equip(Object *);
        virtual bool drop(Object &);
        virtual bool pick_up(Object &);
        virtual bool has_object(std::string) const;
        virtual Object * get_object(std::string) const;

        virtual std::string name() const = 0;
        virtual std::string type() const = 0;
        virtual std::string description() const = 0;
        virtual bool is_player() const;

        inline bool is_alive() { return health > 0; }
        inline Weapon * get_weapon() { return current_weapon; }
        inline void set_weapon(Weapon * weapon) { current_weapon = weapon; }
        inline void clear_weapon() { current_weapon = 0; }
    
        inline Container * get_container() { return current_container; }
        inline void set_container(Container * container) { current_container = container; }
        
        inline Place * get_place() { return current_place; }

        int health;
        int base_damage;
        
        virtual void save(std::ostream &) const;
        
    protected:
        Place * current_place;
        Weapon * current_weapon;
        Container * current_container;
        Controller &controller;
        
    private:
        void go(Place & new_place);
        
        // disable copy and assignment
        Actor(const Actor &);
        Actor & operator=(const Actor &);
};

}

#endif



