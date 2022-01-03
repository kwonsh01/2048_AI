#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>
#include "Shape.h"

#define gotoxy(x,y) printf("\033[%d;%dH", (y+2), (x*2+2) + 1)//¾Æ·¡·Î y+2
#define cRESET "\033[0m"
#define cBLACK "\033[30m"
#define cRED "\033[31m"
#define cGREEN "\033[32m"
#define cYELLOW "\033[33m"
#define cBLUE "\033[34m"
#define cMAGENTA "\033[35m"
#define cCYAN "\033[36m"
#define cWHITE "\033[37m"
#define cBOLDRED "\033[31m"
#define cBOLDGREEN "\033[32m"
#define cBOLDYELLOW "\033[1m\033[33m"
#define cBOLDBLUE "\033[34m"
#define cBOLDMAGENTA "\033[35m"
#define cBOLDCYAN "\033[36m"
#define cBOLDRESET "\033[1m\033[0m"

void display(Shape& shape_);

#endif