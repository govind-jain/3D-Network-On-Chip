CPP := g++
OUTPUT := out
CPPFLAGS := -I. -I./test -I./topology  -DENABLE_PTHREADS=ON


SRC := $(wildcard */*.cpp)

OBJ := $(wildcard $(OUTPUT)/*.o)

all:
	$(CPP) -std=c++11 $(CPPFLAGS) $(SRC)  -o $(OUTPUT)
