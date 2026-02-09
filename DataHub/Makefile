CC=gcc
CFLAGS=-Iinclude
SRC=src/main.c src/cli.c src/commands.c
OUT=datahub.exe

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

clean:
	del datahub.exe
