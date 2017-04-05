LDFLAGS := -lncurses
CPPFLAGS := -g
CXX:= g++
SRC:= $(wildcard *.cpp)
DEP:= $(wildcard *.h)
OUTPUT:= nibbles

all : $(OUTPUT)
$(OUTPUT) : $(SRC) $(DEP)
	$(CXX) -o $(OUTPUT) $(SRC) $(LDFLAGS) $(CPPFLAGS)
