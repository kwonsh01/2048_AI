#ifndef _TILE8_H_
#define _TILE8_H_
#include"Tile.h"

class Tile8 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile8(int x, int y);
	~Tile8();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif