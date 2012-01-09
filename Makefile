
OBJECTS = actor.o controller.o main.o map.o outdoor_place.o place.o wolf.o player.o human.o object.o container.o backpack.o key.o weapon.o sword.o

CFLAGS += -Wall -Wextra -Weffc++ -O2 -std=c++0x -g

CXXTESTPATH=../../cxxtest/
CXXTESTGEN=$(CXXTESTPATH)cxxtestgen.py

all: game

.cpp.o:
	$(CXX) $(CFLAGS) -c $< -o $@

# Header dependencies
# TODO

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

