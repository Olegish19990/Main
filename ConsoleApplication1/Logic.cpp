#include<iostream>  
#include<conio.h>  
#include<dos.h>   
#include <windows.h>  
#include <time.h>
#include "LogicHeader.h"
#include <fstream>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); //- это тип данных, используемый в Windows API для представления дескрипторов объектов, таких как файлы, процессы, потоки и, в данном случае, консольные окна.
COORD Pos; //Создаем обьект для координат


#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

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
	cout << "Хотите сохранить результат?\n1)Да \n2)Нет\n";
	cin >> num;
	if (num == 1) {
		inputResult(coins);
		cout << GREEN << "Ваш рекорд успешно сохранен!";
		cout << RESET << "\n";
	}
	else {
		system("cls");
	}
}