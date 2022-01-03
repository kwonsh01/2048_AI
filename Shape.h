#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <string>

enum Color {
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	BOLDRED,
	BOLDGREEN,
	BOLDYELLOW,
	BOLDBLUE,
	BOLDMAGENTA,
	BOLDCYAN,
};

using namespace std;

class Shape {
	private:
		int x, y;
		string msg;
		Color color;

	public :
		Shape();
		Shape(int, int, Color);
		Shape(int, int, Color, string);
		int getX() const {return x;}
		int getY() const {return y;}
		string getMsg() const {return msg;}
		Color getColor() const {return color;}
		void setX(int x_) {x = x_;}
		void setY(int y_) {y = y_;}
		void setMsg(string msg_) {msg = msg_;}
		void setColor(Color color_) {color = color_;}

		~Shape() {};
};

#endif
