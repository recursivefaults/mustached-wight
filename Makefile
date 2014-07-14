CXX = clang++
SDL = -L /usr/local/lib/ -lSDL2 -lSDL2_image
# If your compiler is a bit older you may need to change -std=c++11 to
# -std=c++0x
CXXFLAGS = -Wall -std=c++11 -I /usr/local/include
LDFLAGS = $(SDL)
SRCDIR = src
EXE = zombie
OBJECTS = 

all: 
	$(CXX) $(CXXFLAGS) src/*.cpp $(LDFLAGS) -o $(EXE)


clean:
	rm gen/*.o;rm $(EXE)
