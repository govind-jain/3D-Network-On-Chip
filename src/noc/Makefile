CPP := g++
OUTPUT := out
CPPFLAGS := -I. -I./routing -I./test -I./topology -I./node -I./types   -DENABLE_PTHREADS=ON


SRC := $(wildcard */*.cpp)

OBJ := $(wildcard $(OUTPUT)/*.o)

all:
	$(CPP) -std=c++11 $(CPPFLAGS) $(SRC)  -o $(OUTPUT)
