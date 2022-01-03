#include <iostream>
#include "display.h"
#include "Shape.h"

using namespace std;

void display(Shape &shape_) {
	gotoxy(shape_.getX(), shape_.getY());
	if (shape_.getColor() == RED)	{
		cout << cRED << shape_.getMsg() << cRESET;
	}
	else if (shape_.getColor() == GREEN)	{
		cout << cGREEN << shape_.getMsg() << cRESET;
	}
	else if (shape_.getColor() == YELLOW)	{
		cout << cYELLOW << shape_.getMsg() << cRESET;
	}
	else if (shape_.getColor() == BLUE)	{
		cout << cBLUE << shape_.getMsg() << cRESET;
	}
	else if (shape_.getColor() == MAGENTA)	{
		cout << cMAGENTA << shape_.getMsg() << cRESET;
	}
	else if (shape_.getColor() == CYAN)	{
		cout << cCYAN << shape_.getMsg() << cRESET;
	}
	else if (shape_.getColor() == WHITE)	{
		cout << cWHITE << shape_.getMsg() << cRESET;
	}
	else if (shape_.getColor() == BOLDRED)	{
		cout << cBOLDRED << shape_.getMsg() << cBOLDRESET;
	}
	else if (shape_.getColor() == BOLDGREEN)	{
		cout << cBOLDGREEN << shape_.getMsg() << cBOLDRESET;
	}
	else if (shape_.getColor() == BOLDYELLOW)	{
		cout << cBOLDYELLOW << shape_.getMsg() << cBOLDRESET;
	}
	else if (shape_.getColor() == BOLDBLUE)	{
		cout << cBOLDBLUE << shape_.getMsg() << cBOLDRESET;
	}
	else if (shape_.getColor() == BOLDMAGENTA)	{
		cout << cBOLDMAGENTA << shape_.getMsg() << cBOLDRESET;
	}
	else if (shape_.getColor() == BOLDCYAN)	{
		cout << cBOLDCYAN << shape_.getMsg() << cBOLDRESET;
	}
	else	{
		cout << shape_.getMsg();
	}
}