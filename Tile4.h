#ifndef _TILE4_H_
#define _TILE4_H_
#include"Tile.h"

class Tile4 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile4(int x, int y);
	~Tile4();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif