//������(Honor Code)
//���� �� ���α׷��� ������ �ٸ� ����� �������� ���� ���� �ϼ��Ͽ����ϴ�.
//I completed this programming task without the improper help of others.
#include <iostream>
#include "Board.h"
#include "Tile.h"
#include "Tile0.h"
#include "Tile2.h"

using namespace std;

int main() {
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
	
	default:
		break;
	}
	
}