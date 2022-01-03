#ifndef _TILE256_H_
#define _TILE256_H_
#include"Tile.h"

class Tile256 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile256(int x, int y);
	~Tile256();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif