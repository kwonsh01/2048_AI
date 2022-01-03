#ifndef _TILE64_H_
#define _TILE64_H_
#include"Tile.h"

class Tile64 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile64(int x, int y);
	~Tile64();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif