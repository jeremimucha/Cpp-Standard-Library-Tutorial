CFLAGS = -O2 -Wall -Wextra -pedantic -std=c++11 -IC:/msys64/mingw64/include \
-IC:/Users/muchajer/Documents/Cpp/Cpp-Standard-Library-Tutorial/incl -LC:/msys64/mingw64/lib
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
