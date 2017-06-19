CFLAGS = -O2 -Wall -Wextra -pedantic -std=c++11
CXX = g++


SRC = $(wildcard *.cpp)
BINS = $(patsubst %.cpp, %.exe, $(SRC))
DEPS = printtuple.hpp

all: $(BINS)

%.exe: %.cpp $(DEPS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS)


.PHONY: all, clean
