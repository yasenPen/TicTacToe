// TicTacToe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Field {
	char a;
	char fld[7][7] = {
		char(218), char(196), char(194), char(196), char(194), char(196), char(191),
		char(179),         a, char(179),         a, char(179),         a, char(179),
		char(195), char(196), char(197), char(196), char(197), char(196), char(180),
		char(179),         a, char(179),         a, char(179),         a, char(179),
		char(195), char(196), char(197), char(196), char(197), char(196), char(180),
		char(179),         a, char(179),         a, char(179),         a, char(179),
		char(192), char(196), char(193), char(196), char(193), char(196), char(217)

	};
public: 
	Field() {
		a =(char) 23;
	};
	void show() {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 7; j++) {
				cout << (int) fld[i][j];
			};
			cout << endl;
		};
	};
};


int main()
{
	setlocale(0, "C");
	Field f;
	//setlocale(LC_ALL, "C");
	f.show();
	system("pause");
    return 0;
}

