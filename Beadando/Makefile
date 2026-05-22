CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lmingw32 -lSDL2main -lSDL2 -lopengl32 -lm

SRC = src/main.c src/app.c src/scene.c src/camera.c src/light.c src/room.c
OUT = haunted_room.exe

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	del $(OUT)