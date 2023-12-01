CXX = g++

CXXFLAGS = -Iinclude
LDFLAGS = -Llib -Wl,-rpath ./lib
LDLIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

SRCS = main.cpp Entity.cpp Animation.cpp Asteroid.cpp Bullet.cpp Player.cpp

TARGET = main

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Clean
clean:
	rm -f $(TARGET)

.PHONY: all clean