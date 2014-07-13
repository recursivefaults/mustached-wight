CXX = clang++
SDL = -L /usr/local/lib/ -lSDL2 -v
# If your compiler is a bit older you may need to change -std=c++11 to
# -std=c++0x
CXXFLAGS = -Wall -v -c -std=c++11 -I /usr/local/include
LDFLAGS = $(SDL)
SRCDIR = src
EXE = zombie
#
all: $(EXE)
#
$(EXE): main.o
	$(CXX) $(LDFLAGS) $< -o $@
#
main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
#
clean:
	rm *.o && rm $(EXE)
