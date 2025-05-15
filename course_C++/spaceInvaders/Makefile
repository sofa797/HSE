CXX = g++                                                           # Компилятор
CXXFLAGS = -std=c++17 -I./include                                     # Флаги компилятора
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lncurses       # Флаги линковки

SRC = main.cpp src/Game.cpp src/Player.cpp src/Enemy.cpp src/Bullet.cpp src/Explosion.cpp # Список исходных файлов
OBJ = $(SRC:.cpp=.o)                                                 # Список объектных файлов

OUT = spaceInvaders                                                  # Имя выходного исполнимого файла

# Правило для создания исполнимого файла
all: $(OUT)

# Правило для сборки исполнимого файла
$(OUT): $(OBJ)
	$(CXX) $(OBJ) -o $(OUT) $(LDFLAGS)

# Правило для компиляции .cpp файлов в .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки объектных файлов и исполнимого файла
clean:
	rm -f $(OBJ) $(OUT)

