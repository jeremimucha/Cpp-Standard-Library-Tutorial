CFLAGS = -O2 -Wall -Wextra -pedantic -std=c++14 -IC:/msys64/mingw64/include \
-I../incl -LC:/msys64/mingw64/lib
CXX = g++


SRC = $(wildcard *.cpp)
BINS = $(patsubst %.cpp, %.exe, $(SRC))
DEPS =


all: $(BINS)

%.exe: %.cpp $(DEPS)
	$(CXX) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(BINS)


.PHONY: all, clean
