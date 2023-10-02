#include<iostream>  
#include<conio.h>  
#include<dos.h>   
#include <windows.h>  
#include <time.h>
#include "LogicHeader.h"
#include <fstream>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //- ��� ��� ������, ������������ � Windows API ��� ������������� ������������ ��������, ����� ��� �����, ��������, ������ �, � ������ ������, ���������� ����.
COORD Pos; //������� ������ ��� ���������


#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

//������� ������� ������
void gotoxy(int x, int y) {
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(console, Pos);
} // ������� ��� ����������� ������� �� �����������.


void PrintMap() {

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 14; j++) {
			cout << "+";
		}
		cout << endl;
	}

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 15; j++) {
			gotoxy(60 - j, i); cout << "+";
		}
		cout << endl;
	}
}//������ �����. ������������� gotoxy ��� ����������� �������




void inputResult(int coins) {
	ofstream recordFill;
	recordFill.open("records.txt");
	recordFill << coins;
	recordFill.close();
}
void SeeResult(int coins) {
	cout << RESET;
	int num = 0;
	ifstream file;
	file.open("records.txt");
	if (!(file >> num))
	{
		file.close();
		inputResult(0);
	}
	cout << "������ ��������� ���������?\n1)�� \n2)���\n";
	cin >> num;
	if (num == 1) {
		inputResult(coins);
		cout << GREEN << "��� ������ ������� ��������!";
		cout << RESET << "\n";
	}
	else {
		system("cls");
	}
}