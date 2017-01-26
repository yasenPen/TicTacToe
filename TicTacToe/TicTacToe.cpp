// TicTacToe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int ct = 1;

class Field {
	char a[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
		// 79 = O; 88 = X
	};
public: 
	void show() {
		char fld[7][7] = {
			{ char(218), char(196), char(194), char(196), char(194), char(196), char(191) },
			{ char(179),   a[0][0], char(179),   a[0][1], char(179),   a[0][2], char(179) },
			{ char(195), char(196), char(197), char(196), char(197), char(196), char(180) },
			{ char(179),   a[1][0], char(179),   a[1][1], char(179),   a[1][2], char(179) },
			{ char(195), char(196), char(197), char(196), char(197), char(196), char(180) },
			{ char(179),   a[2][0], char(179),   a[2][1], char(179),   a[2][2], char(179) },
			{ char(192), char(196), char(193), char(196), char(193), char(196), char(217) }
		};
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				cout << fld[i][j];
			};
			cout << endl;
		};
	};
	void upd(int x, int y) {
		a[x][y] = ct % 2 ? 88 : 79;
		ct++;
	};
	int wincheck() { 
		if (ct > 4) {
			if ((a[0][0] == a[0][1] == a[0][2]) | (a[1][0] == a[1][1] == a[1][2]) | (a[2][0] == a[2][1] == a[2][2]) |
				(a[0][0] == a[1][0] == a[2][0]) | (a[0][1] == a[1][1] == a[2][1]) | (a[0][2] == a[1][2] == a[2][2]) |
				(a[0][0] == a[1][1] == a[2][2]) | (a[2][0] == a[1][1] == a[0][2])) {
				return 0;
			}
			else return 1;
		};
	};
};


int main()
{
	setlocale(0, "C");
	Field f;
	int x, y;
	f.show();
	for (; ct < 10;) {
		static Field f1;
		cout << "\nVvedite x, y - coords yacheiki (ot 0 do 2): ";
		cin >> x >> y;
		if (x >= 0 & x < 3 & y >= 0 & y < 3) {
			f1.upd(x, y);
			system("CLS");
			f1.show();
		}
		else {
			cout << "\nSkazano je, ot 0 do 2\n";
			ct--;
		};
		if (f1.wincheck()) {
			cout << f1.wincheck();
			cout <<"Pozdravlaem " << ct % 2 * 88 + (ct + 1) % 2 * 79 << " c pobedoi!\n\n";
		};
	};
	system("pause");
    return 0;
}

