#ifndef _TILE_H_
#define _TILE_H_
#include "Shape.h"

class Tile {
public:
	Tile(){};
	virtual ~Tile(){};
	virtual int getXBoard() = 0;
	virtual int getYBoard() = 0;
	virtual int getValue() = 0;
	virtual Shape** getShape() = 0;
	virtual void setPosition(int x, int y) = 0;
	virtual bool isMergable(Tile* tile) = 0;
};

#endif