// Персональный шаблон проекта С++
#include <iostream>
#include "windows.h"
#include <string>
#include <fstream>

using namespace std;

const int rows = 3;
const int columns = 3;
char field[rows][columns] = {
	{'_', '_', '_'},
	{'_', '_', '_'},
	{'_', '_', '_'}
};
int turn = 1;

int main() {
	setlocale(LC_ALL, "Russian");
	/*
	SYSTEMTIME date;
	GetSystemTime(&date);
	cout << (date.wHour + 5) << ":" << date.wMinute << endl;
*/
	cout << "Введите название файла: ";
	string path;
	getline(cin,path);
	path = "saves\\" + path + ".save";

	ifstream fin;
	fin.open(path);
	if (!fin.is_open()) {
		cout << "Ошибка открытия сохранения" << endl;

	}
	else {
		cout << "Сохранение открыто" << endl;
		string str;
		int curRow = 0;
		while (!fin.eof()) {
			str = "";
			getline(fin, str);
			if (str[0] == '#' || str == "")
				continue;

			if (str[0] == 'x' || str[0] == '0' || str[0] == '_') {
				for (int i = 0; i < rows; i++) 
					field[curRow][i] = str[i];
				curRow++;
			}

			if (str[0] == '1' || str[0] == '2')
				turn = (int)str[0] - '0';
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
			cout << field[i][j];
		cout << endl;
	}
	cout << turn << endl;



	return 0;
}