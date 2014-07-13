CXX = clang++
SDL = -L /usr/local/lib/ -lSDL2 -lSDL2_image -v
# If your compiler is a bit older you may need to change -std=c++11 to
# -std=c++0x
CXXFLAGS = -Wall -v -c -std=c++11 -I /usr/local/include
LDFLAGS = $(SDL)
SRCDIR = src
EXE = zombie
OBJECTS = src/graphics.o src/game.o src/main.o

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

src/%.o: src/%.cpp 
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm src/*.o;rm *.o;rm $(EXE)
