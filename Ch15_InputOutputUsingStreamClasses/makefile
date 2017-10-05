CFLAGS = -O2 -Wall -Wextra -pedantic -std=c++14 -IC:/msys64/mingw64/include \
-I../incl -LC:/msys64/mingw64/lib -Llib -lsum1a
CXX = g++


SRC = $(wildcard *.cpp)
BINS = $(patsubst %.cpp, %.exe, $(SRC))
LIBSRC = $(wildcard lib/*.cpp)
LIBO = $(patsubst %.cpp, %.o, $(LIBSRC))
LIBS = lib/libsum1a.a
DEPS =


all: $(LIBS) $(BINS)

$(LIBO): $(LIBSRC)
	$(CXX) -c -o $@ $< $(CFLAGS)

$(LIBS): lib $(LIBO)
	ar rcs $@ $(LIBO)
	ranlib $@

%.exe: %.cpp $(DEPS)
	$(CXX) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(BINS)


.PHONY: all, clean
