#ifndef _TILE16_H_
#define _TILE16_H_
#include"Tile.h"

class Tile16 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile16(int x, int y);
	~Tile16();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif