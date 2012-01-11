
OBJECTS = actor.o controller.o direction.o loader.o main.o map.o outdoor_place.o place.o portal.o wolf.o player.o human.o old_man.o object.o container.o backpack.o key.o weapon.o woods.o sword.o

CFLAGS += -Wall -Wextra -Weffc++ -O2 -std=c++0x -g

CXXTESTPATH=../../cxxtest/
CXXTESTGEN=$(CXXTESTPATH)cxxtestgen.py

all: game

.cpp.o:
	$(CXX) $(CFLAGS) -c $< -o $@

# Header dependencies (genereated with gcc -MM *.cpp)
actor.o: actor.cpp actor.h types.h place.h controller.h map.h weapon.h \
 object.h
backpack.o: backpack.cpp backpack.h types.h container.h object.h \
 controller.h map.h
container.o: container.cpp container.h types.h object.h controller.h \
 map.h
controller.o: controller.cpp controller.h types.h map.h actor.h place.h \
 backpack.h container.h object.h key.h player.h human.h sword.h weapon.h \
 wolf.h old_man.h outdoor_place.h direction.h loader.h
direction.o: direction.cpp direction.h
human.o: human.cpp human.h types.h actor.h container.h object.h \
 controller.h map.h backpack.h
key.o: key.cpp key.h types.h object.h controller.h map.h
loader.o: loader.cpp controller.h types.h map.h actor.h place.h \
 backpack.h container.h object.h key.h player.h human.h sword.h weapon.h \
 wolf.h old_man.h outdoor_place.h direction.h woods.h portal.h loader.h
main.o: main.cpp controller.h types.h map.h
map.o: map.cpp map.h types.h place.h
object.o: object.cpp object.h types.h controller.h map.h
old_man.o: old_man.cpp old_man.h types.h human.h actor.h container.h \
 object.h controller.h map.h
outdoor_place.o: outdoor_place.cpp outdoor_place.h types.h place.h \
 direction.h actor.h controller.h map.h
place.o: place.cpp place.h types.h actor.h object.h controller.h map.h
player.o: player.cpp player.h types.h human.h actor.h container.h \
 object.h controller.h map.h
portal.o: portal.cpp portal.h outdoor_place.h types.h place.h direction.h \
 actor.h controller.h map.h
sword.o: sword.cpp sword.h types.h weapon.h object.h controller.h map.h
weapon.o: weapon.cpp weapon.h types.h object.h controller.h map.h
wolf.o: wolf.cpp wolf.h types.h actor.h controller.h map.h
woods.o: woods.cpp woods.h outdoor_place.h types.h place.h direction.h \
 actor.h controller.h map.h


game: $(OBJECTS)
	$(CXX) $(CFLAGS) $(OBJECTS) -o game


# our own test code
tests_gen.cpp: tests.cpp header1.h header2.h
	$(CXXTESTGEN) --error-printer -o $@ tests.cpp

tests: $(OBJECTS) tests_gen.cpp
	g++ -g -o tests -I $(CXXTESTPATH) $(OBJECTS) tests_gen.cpp tests.cpp


.PHONY: clean
clean:
	-$(RM) $(OBJECTS) tests tests_gen.cpp

