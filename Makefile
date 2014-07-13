CXX = clang++
SDL = -L /usr/local/lib/ -lSDL2 -lSDL2_image
# If your compiler is a bit older you may need to change -std=c++11 to
# -std=c++0x
CXXFLAGS = -Wall -c -std=c++11 -I /usr/local/include
LDFLAGS = $(SDL)
SRCDIR = src
EXE = zombie
OBJECTS = src/simple_graphics_component.o src/input_state.o src/guy_input_component.o src/game_object.o src/static_sprite.o src/graphics.o src/game.o src/main.o

all: $(EXE)

$(EXE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

src/%.o: src/%.cpp 
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm src/*.o;rm *.o;rm $(EXE)
