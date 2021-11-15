LFLAGS = -std=c++14 -Wall -DUSEGLEW -lglfw3 -lfreeglut -lglew32 -lSOIL -lglu32 -lopengl32 -lm -I"include"
CC = g++
SRC = src/main.cpp lib/Entity.cpp 
build:
	$(CC) $(SRC) -o output/main $(LFLAGS)
run:
	./output/main
clean:
	rm -f core *.o 

