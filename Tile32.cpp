#include "Tile32.h"
#include <iostream>

using namespace std;

Tile32::Tile32(int x, int y):x_Board(x), y_Board(y) {//make 6*6 Shape array
	value = 32;
	shapes = new Shape*[6];
	for(int i = 0; i < 6; i++){
		shapes[i] = new Shape[6];
	}

	for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            shapes[i][j].setX(6*x_Board + i);
            shapes[i][j].setY(6*y_Board + j);
			shapes[i][j].setColor(BLUE);
        }
    }
	for(int i = 1; i < 5; i++){
        for(int j = 1; j < 5; j++){
			shapes[i][j].setMsg(" ");
        }
    }
	shapes[2][2].setMsg("3");
	shapes[3][2].setMsg("2");
}

Tile32::~Tile32() {
	for(int i = 0; i < 6; i++){
		delete[] shapes[i];
	}
	delete[] shapes;
}

int Tile32::getXBoard() {
	return x_Board;
}

int Tile32::getYBoard(){
	return y_Board;
}

int Tile32::getValue(){
	return value;
}

Shape** Tile32::getShape(){
	return shapes;
}

void Tile32::setPosition(int x, int y){
	x_Board = x;
	y_Board = y;
	for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            shapes[i][j].setX(6*x_Board + i);
            shapes[i][j].setY(6*y_Board + j);
        }
    }
	return;
}

bool Tile32::isMergable(Tile* tile){
	if(value == tile->getValue()){
			return true;
	}
	return false;
}