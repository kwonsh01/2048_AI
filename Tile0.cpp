#include "Tile0.h"
#include <iostream>

using namespace std;

Tile0::Tile0(int x, int y):x_Board(x), y_Board(y) {//make 6*6 Shape array
	value = 0;
	shapes = new Shape*[6];
	for(int i = 0; i < 6; i++){
		shapes[i] = new Shape[6];
	}

	for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            shapes[i][j].setX(6*x_Board + j);
            shapes[i][j].setY(6*y_Board + i);
			shapes[i][j].setMsg(" ");
        }
    }

}

Tile0::~Tile0() {
	for(int i = 0; i < 6; i++){
		delete[] shapes[i];
	}
	delete[] shapes;
}

int Tile0::getXBoard() {
	return x_Board;
}

int Tile0::getYBoard(){
	return y_Board;
}

int Tile0::getValue(){
	return value;
}

Shape** Tile0::getShape(){
	return shapes;
}

void Tile0::setPosition(int x, int y){
	x_Board = x;
	y_Board = y;
	for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            shapes[i][j].setX(6*x_Board + j);
            shapes[i][j].setY(6*y_Board + i);
        }
    }
	return;
}

bool Tile0::isMergable(Tile* tile){
	return false;
}