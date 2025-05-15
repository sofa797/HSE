CXX = g++                                                          
CXXFLAGS = -std=c++17 -I./include                                    
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lncurses       

SRC = main.cpp src/Game.cpp src/Player.cpp src/Enemy.cpp src/Bullet.cpp src/Explosion.cpp
OBJ = $(SRC:.cpp=.o)                                                

OUT = spaceInvaders                                                

all: $(OUT)

$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $(OUT) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT)

