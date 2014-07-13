CXX = clang++
SDL = -L /usr/local/lib/ -lSDL2 -lSDL2_image -v
# If your compiler is a bit older you may need to change -std=c++11 to
# -std=c++0x
CXXFLAGS = -Wall -v -c -std=c++11 -I /usr/local/include
LDFLAGS = $(SDL)

SRCDIR = src
EXE = zombie
zombie:
	clang++ -o zombie src/*.cpp -I /usr/local/include -Wall -std=c++11 -L /usr/local/lib -lSDL2 -lSDL2_image


#all: $(EXE)
#
#$(EXE): *.o 
#	$(CXX) $(LDFLAGS) $< -o $@
#
#%.o: src/%.cpp
#	$(CXX) $(CXXFLAGS) $< -o $@
#
#clean:
#	rm *.o && rm $(EXE)
