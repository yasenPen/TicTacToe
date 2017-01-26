// TicTacToe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Field {
	int count = 0;
	char a[3][3] = {
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
		// 79 = O; 88 = X
	};
	char fld[7][7] = {
		char(218), char(196), char(194), char(196), char(194), char(196), char(191),
		char(179),   a[0][0], char(179),   a[0][1], char(179),   a[0][2], char(179),
		char(195), char(196), char(197), char(196), char(197), char(196), char(180),
		char(179),   a[1][0], char(179),   a[1][1], char(179),   a[1][2], char(179),
		char(195), char(196), char(197), char(196), char(197), char(196), char(180),
		char(179),   a[2][0], char(179),   a[2][1], char(179),   a[2][2], char(179),
		char(192), char(196), char(193), char(196), char(193), char(196), char(217)

	};
public: 
	Field() {
		a;
	};
	void show() {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				cout << fld[i][j];
			};
			cout << endl;
		};
		
	};
	void upd(int x, int y) {
		a[x][y] = count % 2 ? 88 : 79;
		count++;
	};
};


int main()
{
	setlocale(0, "C");
	Field f;
	f.show();
	for(;;)
	system("pause");
    return 0;
}

