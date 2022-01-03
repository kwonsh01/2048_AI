#ifndef _TILE2048_H_
#define _TILE2048_H_
#include"Tile.h"

class Tile2048 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile2048(int x, int y);
	~Tile2048();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif