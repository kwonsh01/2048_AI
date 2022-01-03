CC = g++
TARGET = 20200031_Assignment3.exe 
OBJS =  main.o Board.o display.o Shape.o Tile.o Tile0.o Tile2.o Tile4.o Tile8.o Tile16.o Tile32.o Tile64.o Tile128.o Tile256.o Tile512.o Tile1024.o Tile2048.o

CPLAGS = -g

all: $(TARGET)

20200031_Assignment3.exe: $(OBJS)
	$(CC) $(CPLAGS) -o $@ $^

.cpp.o:
	$(CC) $(CPLAGS) -c -o $@ $<

main.o: Board.h Tile.h Tile0.h Tile2.h Tile4.h main.cpp
Board.o: Shape.h Board.h Board.cpp 
Shape.o: Shape.h Shape.cpp
Tile.o: Shape.h Tile.h Tile.cpp
Tile0.o: Tile.h Tile0.h Tile0.cpp
Tile2.o: Tile.h Tile2.h Tile2.cpp
Tile4.o: Tile.h Tile4.h Tile4.cpp
Tile8.o: Tile.h Tile8.h Tile8.cpp
Tile16.o: Tile.h Tile16.h Tile16.cpp
Tile32.o: Tile.h Tile32.h Tile32.cpp
Tile64.o: Tile.h Tile64.h Tile64.cpp
Tile128.o: Tile.h Tile128.h Tile128.cpp
Tile256.o: Tile.h Tile256.h Tile256.cpp
Tile512.o: Tile.h Tile512.h Tile512.cpp
Tile1024.o: Tile.h Tile1024.h Tile1024.cpp
Tile2048.o: Tile.h Tile2048.h Tile2048.cpp

clean:
	rm -f 20200031_Assignment3.exe $(OBJS)