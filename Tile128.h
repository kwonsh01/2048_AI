#ifndef _TILE128_H_
#define _TILE128_H_
#include"Tile.h"

class Tile128 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile128(int x, int y);
	~Tile128();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif