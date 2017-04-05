LDFLAGS := -lncurses
CPPFLAGS := -g
CXX:= g++
SRC:= $(wildcard *.cpp)
DEP:= $(wildcard *.h)
DEP+= $(wildcard *.hpp)
OUTPUT:= nibbles

all : $(OUTPUT)
$(OUTPUT) : $(SRC) $(DEP)
	$(CXX) -o $(OUTPUT) $(SRC) $(LDFLAGS) $(CPPFLAGS)
