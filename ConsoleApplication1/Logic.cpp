#include<iostream>  
#include<conio.h>  
#include<dos.h>   
#include <windows.h>  
#include <time.h>
#include "LogicHeader.h"
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //- ��� ��� ������, ������������ � Windows API ��� ������������� ������������ ��������, ����� ��� �����, ��������, ������ �, � ������ ������, ���������� ����.
COORD Pos; //������� ������ ��� ���������

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


