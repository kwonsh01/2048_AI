#ifndef _TILE512_H_
#define _TILE512_H_
#include"Tile.h"

class Tile512 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile512(int x, int y);
	~Tile512();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif