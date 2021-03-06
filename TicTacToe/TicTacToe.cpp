﻿// TicTacToe.cpp: определяет точку входа для консольного приложения.
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
		if (a[0][0] & a[1][1] & a[2][2])
		{
			if (a[0][0] == a[0][1] & a[0][1] == a[0][2] | a[1][0] == a[1][1] & a[1][1] == a[1][2] | a[2][0] == a[2][1] & a[2][1] == a[2][2] |
				a[0][0] == a[1][0] & a[1][0] == a[2][0] | a[0][1] == a[1][1] & a[1][1] == a[2][1] | a[0][2] == a[1][2] & a[1][2] == a[2][2] |
				a[0][0] == a[1][1] & a[1][1] == a[2][2] | a[0][2] == a[1][1] & a[1][1] == a[2][0]) {
				ct += 6;
				return 0;
			}
		};
	return -1;
	};
};


int main()
{
	setlocale(0, "C");
	Field *f = new (Field);
	int x, y;
	flag :
	f->show();
	for (; ct < 10;) {
		static Field *f1 = new (Field);
		cout << "\nVvedite x, y - coords yacheiki (ot 0 do 2): ";
		cin >> x >> y;
		if (x >= 0 & x < 3 & y >= 0 & y < 3) {
			f1->upd(x, y);
			system("CLS");
			f1->show();
		}
		else {
			cout << "\nSkazano je, ot 0 do 2\n";
		};
		if (!f1->wincheck()) {
			cout << f1->wincheck();
			cout <<"\nPozdravlaem " << (char) ((ct + 1) % 2 * 88 + ct % 2 * 79) << " c pobedoi!\nWanna play again? (y/n): ";
			delete f1;
		};
		if (ct == 10 & f1->wincheck() == -1) {
			delete f1;
			cout << "Draw! Wanna play again? (y/n): ";
		};
	};
	char resp;
	cin >> resp;
	if (resp == 'y') {
		system("CLS");
		ct = 1;
		delete f;
		Field *f = new (Field);
		goto flag;
	}
	else cout << "\nBye!\n";
	system("pause");
    return 0;
}

