CFLAGS = -O2 -Wall -Wextra -pedantic -std=c++11
CXX = g++


SRC = $(wildcard *.cpp)
OBJ = 
BINS = $(patsubst %.cpp, %.exe, $(SRC))
DEPS = clock.hpp timepoint.hpp

all: $(BINS)

%.exe: %.cpp $(DEPS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS)


.PHONY: all, clean
