#ifndef _BOARD_H_
#define _BOARD _H_
#include <iostream>
#include <fstream>
#include "display.h"
#include "Tile.h"

class Board {
private:
    Tile*** board;
    int score;
    ofstream outfile;
public:
    Board();
    ~Board();
    void initialize();
    void printboard();
    void random_Tile(int count = 1);
    void start_game();
    bool moveable();
    bool mergable();
    bool merge(char input, bool& score_change);
    int move_w();
    int move_a();
    int move_s();
    int move_d();
    bool move(char input, bool& score_change);
};

#endif