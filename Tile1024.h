#ifndef _TILE1024_H_
#define _TILE1024_H_
#include"Tile.h"

class Tile1024 : public Tile {
private:
	int value;
	int x_Board;
	int y_Board;
	Shape** shapes;
public:
	Tile1024(int x, int y);
	~Tile1024();
	int getXBoard();
	int getYBoard();
	int getValue();
	Shape** getShape();
	void setPosition(int x, int y);
	bool isMergable(Tile* tile);
};

#endif