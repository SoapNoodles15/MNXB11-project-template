CXX := g++
CXXWARNINGS := -Wall -Wextra -Werror
CXXOPT := -O3
CXXSTD := -std=c++17

ROOTLIBS := $(shell root-config --glibs)


INCLUDES := -I include -I external/include -I external/include/fmt -I external/include/date/ -I$(shell root-config --incdir)
LIBDIRS := -L external/lib64
LDFLAGS := $(LIBDIRS) $(ROOTLIBS) -lfmt

CXXFLAGS := $(CXXWARNINGS) $(CXXSTD) $(CXXOPT) $(INCLUDES)

.PHONY: all clean


all: main


main: main.cxx
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

src/%.o: src/%.cxx
	$(CXX) $(CXXFLAGS) $^ -c -o $@

clean:
	rm -v src/*.o main