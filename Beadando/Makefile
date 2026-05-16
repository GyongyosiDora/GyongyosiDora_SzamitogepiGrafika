CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lmingw32 -lSDL2main -lSDL2 -lopengl32

SRC = src/main.c
OUT = haunted_room.exe

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	del $(OUT)