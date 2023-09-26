// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "LogicHeader.h"
#include<iostream>  
#include<conio.h>  
#include<dos.h>   
#include <windows.h>  
#include <time.h>

using namespace std;
int car_position = 30;
int Enemy_position1Y = 0;
int Enemy_position1X = 25;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
//Для удобства создадим макросы стрелочек для управления машины

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"
//Создаем макросы цветов

int sist = 1;
bool gameLive = false;
bool Enemy = false;
//Создаем перменные для основной логики игры



void SpawnEnemy() {
	if (Enemy == true) {
		gotoxy(Enemy_position1X, Enemy_position1Y);
		cout<<RED<<"****";
		gotoxy(Enemy_position1X, Enemy_position1Y + 1);
		cout <<"****";
		gotoxy(Enemy_position1X, Enemy_position1Y + 1);
		cout <<"****";
	}
	cout << RESET;
}//Ресует врага

void deleteEnemy() {
	gotoxy(Enemy_position1X, Enemy_position1Y);
	cout << "    ";
	gotoxy(Enemy_position1X, Enemy_position1Y + 1);
	cout << "    ";
	gotoxy(Enemy_position1X, Enemy_position1Y + 1);
	cout << "    ";
}//Удаляет машину врага со старыми координатами

void EnemyChans() 
{
	srand(time(NULL));
	Enemy = true;
	Enemy_position1Y = 0;
	Enemy_position1X = 15+rand()%(25);
}//Функция для установки координатов врагу.
char player_car[3][4] = {
	'#','#','#',
	'#','#','#',
	'#','#','#',
	'#','#','#',
}; //Машина игрока

void SetPlayer() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			gotoxy(car_position + j, i + 20);
			cout << player_car[i][j];
		}
	}
	
}//Ресует машину игрока
void DeletePlayer() 
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			gotoxy(car_position + j, i + 20);
			cout <<" ";
		}
	}

}//Удаляет машину игрока со старыми координатами 


void sistings() 
{
	int n = 0;
	cout << "Какой способ управление вы выберите\n1)По стрелочкам\n2)По буква(A - влево и D - вправо. ВНИМАНИЕ язык должен быть английским): ";
	cin >> n;
	if (n == 1) {
		sist = 1;
	}
	else {
		sist = 2;
	}
	system("cls");



}//Даем пользователю возмжность выбрать один из предложеных видов управления
void Menu(); //Создаем протатив функции меню
void Hit(int coins)
{

	int v = 0;

	if (Enemy_position1Y + 4 >= 23) {
		if (Enemy_position1X + 4 >= car_position && Enemy_position1X < car_position + 4) { // //Эта часть условия проверяет, находится ли позиция противника (прибавленная к 4) справа от или на одной и той же горизонтальной позиции, что и машина игрока. Если это условие истинно, это означает, что противник находится справа от машины игрока и находится в определенной близости.

			gameLive = false;
			system("cls");
			cout<<RED<< "Вы проиграли, вы заработали: " <<YELLOW<<coins<<RED<< " очков "<<endl;
			cout<<GREEN<< "1) Выйти в главное меню     "<<BLUE<<" 2) Выйти из игры\n";
			cout << RESET;
			cin >> v;
			if (v == 1) {
				Menu();
			}
			else {
				cout << "\nВыходим из игры....";
			}
		}
	}


}//Логика отвичающия за попданию машины врага по игроку.


void game() 
{

	system("cls");
	int coins = 0;
	PrintMap();
	Enemy_position1Y = 0;
	while (gameLive)
	{
		if (Enemy == false) {
			EnemyChans();
		}
		if (_kbhit()) { //Управление машиной игрока
			char key = _getch();
			if (sist == 1) {
				if (key == KEY_RIGHT && car_position < 39)
				{
					car_position += 4;
				}

				else if (key == KEY_LEFT && car_position > 17)
				{
					car_position -= 4;
				}
			}
			else {
				if ((key == 'd' || key == 'D') && car_position < 39)
				{
					car_position += 4;
				}

				else if ((key == 'A' || key == 'a') && car_position > 17)
				{
					car_position -= 4;
				}
			}
		}

		SetPlayer();
		SpawnEnemy();
		Hit(coins); //Проверим, попал ли враг по машине
		Sleep(45); 
		DeletePlayer(); //Удалим игрока со старыми координатами
		deleteEnemy(); //Удалим врага.
		if (Enemy_position1Y >= 25)  //Если враг вышел за границу то удалем его и добавляем очки.
		{
			Enemy = false;
			coins++;
		}
		else if (Enemy == true && Enemy_position1Y < 25) //Если машина врага не вышла за границу то увеличивает координату Y врага на 1
		{
			Enemy_position1Y++;

		}
	}

} //Логика самой игры




void Menu() {

	system("cls");
	int c = 0;
	int n = 0;
	cout << "====================" << endl;
	cout << "   Добро пожаловать в" << endl;
	cout << "       Гонки" << endl;
	cout << "====================" << endl;
	cout << "Выберите опцию:" << endl;
	cout << BLUE << "1) Игра" << endl;
	cout << "2) Правила" << endl;
	cout << "3) Управление" << endl;
	cout << "4) Выйти" << endl;
	cout << RESET << "Введите номер опции: ";
	cin >> c;

	switch (c) {
	case 1:

		gameLive = true;
		game();
		break;
	case 2:
		cout << "Правила игры:" << endl;
		cout << "На вас едут противники(машины) ваша задача уклоняться от них как можно дольше, дольше продержитись - больше очков" << endl;
		cout << "Нажмите 1 что бы вернуться назад в меню" << endl;
		cin >> n;
		if (n == 1) {
			Menu();
		}
		break;
	case 3:

		cout << "Управление:" << endl;
		sistings();
		cout << "Нажмите 1 что бы вернуться назад в меню" << endl;

		cin >> n;
		if (n == 1) {
			Menu();
		}
		break;
	case 4:
		cout << "Выход из игры. До свидания!" << endl;
	default:
		cout << "Неверный выбор. Попробуйте ещё раз." << endl;
		Menu();
		break;
	}
} //Меню игрі





int main()
{
	
	setlocale(LC_ALL, "rus");
	Enemy = true;
	Menu();
	system("cls");
}

