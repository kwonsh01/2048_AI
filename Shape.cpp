#include <iostream>
#include "Shape.h"

using namespace std;

Shape::Shape(){
	x = 0;
	y = 0;
	color = WHITE;
	msg = "бс";
}

Shape::Shape(int x_, int y_, Color color_) {
	x = x_;
	y = y_;
	color = color_;
	msg ="бс";
}

Shape::Shape(int x_, int y_, Color color_, string msg_) {
	x = x_;
	y = y_;
	color = color_;
	msg = msg_;
}