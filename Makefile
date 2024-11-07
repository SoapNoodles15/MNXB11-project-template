CXX := g++
CXXWARNINGS := -Wall -Wextra -Werror
CXXOPT := -O3
CXXSTD := -std=c++17


INCLUDES := -I include -I external/include 
LIBDIRS := -L /project/external/lib -L /project/external/lib64
LDFLAGS := $(LIBDIRS) 

CXXFLAGS := $(CXXWARNINGS) $(CXXSTD) $(CXXOPT) $(INCLUDES)

.PHONY: all clean


all: main


main: main.cxx
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compiling individual object files
src/%.o: src/%.cxx
	$(CXX) $(CXXFLAGS) $^ -c -o $@

# Cleaning the build artifacts
clean:
	rm -v src/*.o main

