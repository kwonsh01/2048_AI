#ifndef _TILE0_H_
#define _TILE0_H_
#include "Tile.h"

class Tile0 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile0(int x, int y);
	~Tile0();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif