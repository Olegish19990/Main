#include<iostream>  
#include<conio.h>  
#include<dos.h>   
#include <windows.h>  
#include <time.h>
#include "LogicHeader.h"
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //- это тип данных, используемый в Windows API для представления дескрипторов объектов, таких как файлы, процессы, потоки и, в данном случае, консольные окна.
COORD Pos; //Создаем обьект для координат

//Создаем макросы цветов
void gotoxy(int x, int y) {
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(console, Pos);
} // Функция для перемещения курсора по координатам.


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
}//Ресует карту. Используеться gotoxy для перемещения курсора


