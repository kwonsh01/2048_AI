#include <iostream>
#include "Board.h"
#include "Tile.h"
#include "Tile0.h"
#include "Tile2.h"

using namespace std;

int main() {
	system("clear");
	Board board;
	int option;
	cout << "----------------------------------\n" << endl;
	cout << "Which Game Do You Want to Play" << endl;
	cout << "1. Player" << endl << "2. AI\n" << endl;
	cout << "----------------------------------\n" << endl;
	cin >> option;

	switch (option) {
	case 1:
		board.start_game();
		break;
	case 2:
		board.start_AI(1);
		break;
	default:
		break;
	}
}