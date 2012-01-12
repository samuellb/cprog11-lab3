#ifndef HUMAN_H
#define HUMAN_H

#include "types.h"
#include "actor.h"
#include "container.h"
#include <string>

namespace game {

class Human : public Actor {
    
    public:
        Human(Controller &, Place &);
        Human(Controller &, Place &, unsigned int, unsigned int);
        virtual ~Human();
   
        virtual bool equip(Object *);
        virtual bool drop(Object &);
        virtual bool pick_up(Object &);
        virtual bool has_object(std::string) const;
        virtual Object *get_object(std::string) const;

        virtual std::string name() const = 0;
        virtual std::string type() const = 0;
        virtual std::string description() const = 0;

    private:
        // disable copy and assignment
        Human(const Human &);
        Human & operator=(const Human &);
};

}

#endif
