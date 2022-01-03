#ifndef _TILE32_H_
#define _TILE32_H_
#include"Tile.h"

class Tile32 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile32(int x, int y);
	~Tile32();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif