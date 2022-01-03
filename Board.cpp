#include "Board.h"
#include "Tile0.h"
#include "Tile2.h"
#include "Tile4.h"
#include "Tile8.h"
#include "Tile16.h"
#include "Tile32.h"
#include "Tile64.h"
#include "Tile128.h"
#include "Tile256.h"
#include "Tile512.h"
#include "Tile1024.h"
#include "Tile2048.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <conio.h>

Board::Board(): score(0), outfile("score.txt"){//make 4*4 Tile* array
	board = new Tile**[4];
	for(int i = 0; i < 4; i++){
		board[i] = new Tile*[4];
	}
}

Board::~Board(){//delete 4*4 Tile* array
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            delete board[i][j]; 
        }
    }

	for(int i = 0; i < 4; i++){
		delete board[i];
	}
	delete[] board;

    outfile.close();
}

void Board::initialize(){//make 4*4 Tile0 array
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            board[j][i] = new Tile0(j, i);
        }
    }
}

void Board::printboard(){//display board
    system("clear");
    for(int i = 0; i < 26; i++){
        printf("\033[%d;%dH", 1, 2*i + 1);
        cout << "●";
        printf("\033[%d;%dH", 26, 2*i + 1);
        cout << "●";
        printf("\033[%d;%dH", i + 1, 1);
        cout << "●";
        printf("\033[%d;%dH", i + 1, 51);
        cout << "●";
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Shape** temp = board[j][i]->getShape();//get shapes
            for(int x = 0; x < 6; x++){
                for(int y = 0; y < 6; y++){
                    display(temp[x][y]);//using display function
                }
            }
        }
    }

    printf("\033[%d;%dH", 8, 53);
    cout << "====================";
    printf("\033[%d;%dH", 10, 53);
    cout << "Score: " << score;
    printf("\033[%d;%dH", 13, 53);
    cout << "====================";

    printf("\033[%d;%dH", 26, 1);
    cout << endl;
}

void Board::random_Tile(int count){             //Make two random tile (2 or 4)
    srand((unsigned int)time(NULL));
    int rannum;
    int x;
    int y;
    int cnt = 0;
    while(cnt < count){
        x = rand() % 4;
        y = rand() % 4;
        rannum = 2 * (rand() % 2 + 1);          //random pick 2 or 4
        if (!board[x][y]->getValue()) {         //if empty tile
            if (rannum == 2) {
                delete board[x][y];
                board[x][y] = new Tile2(x, y);  //make new tile
            }
            else {
                delete board[x][y];
                board[x][y] = new Tile4(x, y);  //make new tile
            }
            cnt++;
        }
    } 
}

void Board::start_game(){//important game control function
    bool num_2048 = false;                  //decide whether to win or lose
    bool score_change = false;              //decide whether to write scores to a text file
    (*this).initialize();//make 4*4 Tile0 board
    (*this).random_Tile(2);//2 random tile
    (*this).printboard();//display
	while(true){
        char input;
        cout << "Press The Next input: ";
        cin >> input;                       //input(w,a,s,d)
        switch (int(input)) {
        case 119:
        case 87:
        case 97:
        case 65:
        case 115:
        case 83:
        case 100:
        case 68:
            num_2048 = (*this).move(input, score_change);//move and merge tile
            break;
        default:
            printf("\033[%d;%dH", 28, 0);
            cout << "Wrong Input!";
            break;
        }
        if(score_change){                   //score was changed -> write to text file
            outfile << score << endl;
            score_change = false;
        }
        
        (*this).printboard();
        
        if(this->moveable()){       //check moveable
            if(num_2048){           //if make 2048 tile
                outfile << "You Won!";  //win
                printf("\033[%d;%dH", 28, 0);
                cout << "You Won!";
                return;
            }
        }
        else{   //cna't move
            outfile << "You Lost!";
            printf("\033[%d;%dH", 28, 0);
            cout << "You Lost!";
            return;
        }
    }
	
}

bool Board::moveable(){                         //true: moveable, false: can't move(game ended)
    for(int i = 0; i < 4; i++){                 //Find emtpy tile
        for(int j = 0; j < 4; j++){
            if(!board[i][j]->getValue()){
                //std::cout << "moveable" << std::endl;
                return true;
            } 
        }
    }
    for(int i = 0; i < 3; i++){                 //Find mergeable tile
        for(int j = 0; j < 3; j++){
            if( (board[i][j]->isMergable(board[i][j + 1])) || (board[i][j]->isMergable(board[i + 1][j])) || (board[i + 1][j + 1]->isMergable(board[i + 1][j])) || (board[i + 1][j + 1]->isMergable(board[i][j + 1]))){
                //std::cout << "moveable" << std::endl;
                return true;
            }
        }
    }
    return false;
}//empty tiles exist or mergeable tile exists -> moveable

bool Board::mergable(){
    for(int i = 0; i < 3; i++){                 //Find mergeable tile
        for(int j = 0; j < 3; j++){
            if( (board[i][j]->isMergable(board[i][j + 1])) || (board[i][j]->isMergable(board[i + 1][j])) || (board[i + 1][j + 1]->isMergable(board[i + 1][j])) || (board[i + 1][j + 1]->isMergable(board[i][j + 1]))){
                return true;
            }
        }
    }
    return false;
}

bool Board::merge(char input, bool& score_change){//2048 -> true
    bool num2048 = false;
    if(input == 'w'){
        for(int j = 0; j < 3; j++){//check from above
            for(int i = 0; i < 4; i++){
                if(board[i][0 + j]->isMergable(board[i][1 + j])){   //check mergeable
                    int temp = board[i][1 + j]->getValue();
                    if(temp == 0){
                        continue;
                    }
                    delete board[i][0 + j];
                    delete board[i][1 + j];

                    board[i][1 + j] = new Tile0(i, 1 + j);

                    score_change = true;

                    switch (temp) {//merge
                    case 2: board[i][0 + j] = new Tile4(i, 0 + j); score+=4; break;
                    case 4: board[i][0 + j] = new Tile8(i, 0 + j); score+=8; break;
                    case 8: board[i][0 + j] = new Tile16(i, 0 + j); score+=16; break;
                    case 16: board[i][0 + j] = new Tile32(i, 0 + j); score+=32; break;
                    case 32: board[i][0 + j] = new Tile64(i, 0 + j); score+=64; break;
                    case 64: board[i][0 + j] = new Tile128(i, 0 + j); score+=128; break;
                    case 128: board[i][0 + j] = new Tile256(i, 0 + j); score+=256; break;
                    case 256: board[i][0 + j] = new Tile512(i, 0 + j); score+=512; break;
                    case 512: board[i][0 + j] = new Tile1024(i, 0 + j); score+=1024; break;
                    case 1024:board[i][0 + j] = new Tile2048(i, 0 + j); score+=2048; num2048=true; break;
                    }
                }
            }
        }
        this->move_w();
        return num2048;
    }
    else if(input == 's'){//check from below
        for(int j = 3; j > 0; j--){
            for(int i = 0; i < 4; i++){
                if(board[i][0 + j]->isMergable(board[i][j - 1])){   //check mergeable
                    int temp = board[i][j - 1]->getValue();
                    if(temp == 0){
                        continue;
                    }
                    delete board[i][0 + j];
                    delete board[i][j - 1];
                    
                    board[i][j - 1] = new Tile0(i, j - 1);

                    score_change = true;

                    switch (temp) {//merge
                    case 2: board[i][0 + j] = new Tile4(i, 0 + j); score+=4; break;
                    case 4: board[i][0 + j] = new Tile8(i, 0 + j); score+=8; break;
                    case 8: board[i][0 + j] = new Tile16(i, 0 + j); score+=16; break;
                    case 16: board[i][0 + j] = new Tile32(i, 0 + j); score+=32; break;
                    case 32: board[i][0 + j] = new Tile64(i, 0 + j); score+=64; break;
                    case 64: board[i][0 + j] = new Tile128(i, 0 + j); score+=128; break;
                    case 128: board[i][0 + j] = new Tile256(i, 0 + j); score+=256; break;
                    case 256: board[i][0 + j] = new Tile512(i, 0 + j); score+=512; break;
                    case 512: board[i][0 + j] = new Tile1024(i, 0 + j); score+=1024; break;
                    case 1024:board[i][0 + j] = new Tile2048(i, 0 + j); score+=2048; num2048=true; break;
                    }
                }
            }
        }
        this->move_s();
        return num2048;
    }
    else if(input == 'a'){//check from left
        for(int j = 0; j < 3; j++){
            for(int i = 0; i < 4; i++){
                if(board[0 + j][i]->isMergable(board[1 + j][i])){   //check mergeable
                    int temp = board[1 + j][i]->getValue();
                    if(temp == 0){
                        continue;
                    }
                    delete board[0 + j][i];
                    delete board[1 + j][i];

                    board[1 + j][i] = new Tile0(1 + j, i);

                    score_change = true;

                    switch (temp) {//merge
                    case 2: board[0 + j][i] = new Tile4(0 + j, i); score+=4; break;
                    case 4: board[0 + j][i] = new Tile8(0 + j, i); score+=8; break;
                    case 8: board[0 + j][i] = new Tile16(0 + j, i); score+=16; break;
                    case 16: board[0 + j][i] = new Tile32(0 + j, i); score+=32; break;
                    case 32: board[0 + j][i] = new Tile64(0 + j, i); score+=64; break;
                    case 64: board[0 + j][i] = new Tile128(0 + j, i); score+=128; break;
                    case 128: board[0 + j][i] = new Tile256(0 + j, i); score+=256; break;
                    case 256: board[0 + j][i] = new Tile512(0 + j, i); score+=512; break;
                    case 512: board[0 + j][i] = new Tile1024(0 + j, i); score+=1024; break;
                    case 1024:board[0 + j][i] = new Tile2048(0 + j, i); score+=2048; num2048=true; break;
                    }
                }
            }
        }
        this->move_a();
        return num2048;
    }
    else{
        for(int j = 3; j > 0; j--){//check from right
            for(int i = 0; i < 4; i++){
                if(board[0 + j][i]->isMergable(board[j - 1][i])){   //check mergeable
                    int temp = board[j - 1][i]->getValue();
                    if(temp == 0){
                        continue;
                    }
                    delete board[0 + j][i];
                    delete board[j - 1][i];

                    board[j - 1][i] = new Tile0(j - 1, i);

                    score_change = true;

                    switch (temp) {//merge
                    case 2: board[0 + j][i] = new Tile4(0 + j, i); score+=4; break;
                    case 4: board[0 + j][i] = new Tile8(0 + j, i); score+=8; break;
                    case 8: board[0 + j][i] = new Tile16(0 + j, i); score+=16; break;
                    case 16: board[0 + j][i] = new Tile32(0 + j, i); score+=32; break;
                    case 32: board[0 + j][i] = new Tile64(0 + j, i); score+=64; break;
                    case 64: board[0 + j][i] = new Tile128(0 + j, i); score+=128; break;
                    case 128: board[0 + j][i] = new Tile256(0 + j, i); score+=256; break;
                    case 256: board[0 + j][i] = new Tile512(0 + j, i); score+=512; break;
                    case 512: board[0 + j][i] = new Tile1024(0 + j, i); score+=1024; break;
                    case 1024:board[0 + j][i] = new Tile2048(0 + j, i); score+=2048; num2048=true; break;
                    }
                }
            }
        }
        this->move_d();
        return num2048;
    }
}
//move_w, move_a, move_s, move_d use same algorithm
//similar to bubble sort
//count check moved tile
int Board::move_w(){
    int count = 0;
    for (int x = 0; x < 4; x++) {
        for(int y = 3; y > 0; y--) {
            for(int i = 0; i < y; i++){
                if(!board[x][i]->getValue()){
                    Tile *temp = board[x][i + 1];
                    board[x][i + 1] = board[x][i];
                    board[x][i + 1]->setPosition(x, i + 1);
                    board[x][i] = temp;
                    board[x][i]->setPosition(x, i); 
                    if(!(board[x][i + 1]->getValue() == temp->getValue())){
                        count++;
                    } 
                }
            }
        }
    }
    return count;
}

int Board::move_a(){
    int count = 0;
    for (int x = 0; x < 4; x++) {
        for(int y = 3; y > 0; y--) {
            for(int i = 0; i < y; i++){
                if(!board[i][x]->getValue()){
                    Tile *temp = board[i + 1][x];
                    board[i + 1][x] = board[i][x];
                    board[i + 1][x]->setPosition(i + 1, x);
                    board[i][x] = temp;
                    board[i][x]->setPosition(i, x);  
                    if(!(board[i + 1][x]->getValue() == temp->getValue())){
                        count++;
                    } 
                }
            }
        }
    }
    return count;
}

int Board::move_s(){
    int count = 0;
    for (int x = 0; x < 4; x++) {
        for(int y = 0; y < 4; y++) {
            for(int i = 3; i > y; i--){
                if(!board[x][i]->getValue()){
                    Tile *temp = board[x][i - 1];
                    board[x][i - 1] = board[x][i];
                    board[x][i - 1]->setPosition(x, i - 1);
                    board[x][i] = temp;
                    board[x][i]->setPosition(x, i);  
                    if(!(board[x][i - 1]->getValue() == temp->getValue())){
                        count++;
                    } 
                }
            }
        }
    }
    return count;
}

int Board::move_d(){
    int count = 0;
    for (int x = 0; x < 4; x++) {
        for(int y = 0; y < 4; y++) {
            for(int i = 3; i > y; i--){
                if(!board[i][x]->getValue()){
                    Tile *temp = board[i - 1][x];
                    board[i - 1][x] = board[i][x];
                    board[i - 1][x]->setPosition(i - 1, x);
                    board[i][x] = temp;
                    board[i][x]->setPosition(i, x); 
                    if(!(board[i - 1][x]->getValue() == temp->getValue())){
                        count++;
                    }  
                }
            }
        }
    }
    return count;
}

bool Board::move(char input, bool& score_change){//move & merge & make random tile
    int count = 0;
    bool temp = false;
    if(input == 'w'){
        count = this->move_w();
    }
    else if(input == 'a'){
        count = this->move_a();
    }
    else if(input == 's'){
        count = this->move_s();   
    }
    else{
        count = this->move_d();
    }

    if(!count && !this->mergable()){//can't merge
        printf("\033[%d;%dH", 28, 0);
        cout << "Nothing Moved!";
        return false;
    }
    else{
        temp = merge(input, score_change);//merge
        (*this).random_Tile();
        return temp;
    }
}