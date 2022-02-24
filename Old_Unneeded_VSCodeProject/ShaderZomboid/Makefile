LFLAGS = -std=c++14 -Wall -DUSEGLEW -lglfw3 -lfreeglut -lglew32 -lSOIL -lglu32 -lopengl32 -lm -I"include"
CC = g++
SRC = src/main.cpp lib/Interface.cpp lib/Game.cpp lib/Entity.cpp lib/Projectile.cpp lib/Zombie.cpp  lib/Shader.cpp lib/VBO.cpp lib/VAO.cpp lib/EBO.cpp lib/Texture.cpp
build:
	$(CC) $(SRC) -o output/main $(LFLAGS)
run:
	./output/main
clean:
	rm -f core *.o 

