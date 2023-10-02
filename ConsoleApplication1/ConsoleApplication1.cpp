// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "LogicHeader.h"
#include<iostream>  
#include<conio.h>  
#include<dos.h>   
#include <windows.h>  
#include <time.h>
#include <fstream>
#include <string>
using namespace std;
int car_position = 30;
int Enemy_position1Y = 0;
int Enemy_position1X = 25;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
//��� �������� �������� ������� ��������� ��� ���������� ������

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

//������� ������� ������

int sist = 1;
bool gameLive = false;
bool Enemy = false;
//������� ��������� ��� �������� ������ ����



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
}//������ �����

void deleteEnemy() {
	gotoxy(Enemy_position1X, Enemy_position1Y);
	cout << "    ";
	gotoxy(Enemy_position1X, Enemy_position1Y + 1);
	cout << "    ";
	gotoxy(Enemy_position1X, Enemy_position1Y + 1);
	cout << "    ";
}//������� ������ ����� �� ������� ������������

void EnemyChans() 
{
	srand(time(NULL));
	Enemy = true;
	Enemy_position1Y = 0;
	Enemy_position1X = 15+rand()%(25);
}//������� ��� ��������� ����������� �����.
char player_car[3][4] = {
	'#','#','#',
	'#','#','#',
	'#','#','#',
	'#','#','#',
}; //������ ������

void SetPlayer() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			gotoxy(car_position + j, i + 20);
			cout << player_car[i][j];
		}
	}
	
}//������ ������ ������
void DeletePlayer() 
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			gotoxy(car_position + j, i + 20);
			cout <<" ";
		}
	}

}//������� ������ ������ �� ������� ������������ 

void sistings() 
{
	int n = 0;
	cout << "����� ������ ���������� �� ��������\n1)�� ����������\n2)�� �����(A - ����� � D - ������. �������� ���� ������ ���� ����������): ";
	cin >> n;
	if (n == 1) {
		sist = 1;
	}
	else {
		sist = 2;
	}
	system("cls");



}//���� ������������ ���������� ������� ���� �� ����������� ����� ����������
//void inputResult(int coins) {
//	ofstream recordFill;
//	recordFill.open("records.txt");
//	recordFill << coins;
//	recordFill.close();
//}
//void SeeResult(int coins) {
//	cout << RESET;
//	int num = 0;
//	ifstream file;
//	file.open("records.txt");
//	if (!(file >> num))
//	{
//		file.close();
//		inputResult(0);
//	}
//	cout << "������ ��������� ���������?\n1)�� \n2)���\n";
//	cin >> num;
//	if (num == 1) {
//			inputResult(coins);
//			cout << GREEN << "��� ������ ������� ��������!";
//			cout << RESET <<"\n";
//	}
//	else {
//		system("cls");
//		}
//}


void Menu(); //������� �������� ������� ����
void Hit(int coins)
{

	int v = 0;

	if (Enemy_position1Y + 4 >= 23) {
		if (Enemy_position1X + 4 >= car_position && Enemy_position1X < car_position + 4) { // //��� ����� ������� ���������, ��������� �� ������� ���������� (������������ � 4) ������ �� ��� �� ����� � ��� �� �������������� �������, ��� � ������ ������. ���� ��� ������� �������, ��� ��������, ��� ��������� ��������� ������ �� ������ ������ � ��������� � ������������ ��������.

			gameLive = false;
			system("cls");
			cout<<RED<< "�� ���������, �� ����������: " <<YELLOW<<coins<<RED<< " ����� "<<endl;
			SeeResult(coins);
			cout<<GREEN<< "1) ����� � ������� ����     "<<BLUE<<" 2) ����� �� ����\n";
			cout << RESET;
			cin >> v;
			if (v == 1) {
				Menu();
			}
			else {
				cout << "\n������� �� ����....";
			}
		}
	}


}//������ ���������� �� �������� ������ ����� �� ������.


void game() 
{

	system("cls");
	int coins = 0;
	PrintMap();
	Enemy_position1Y = 0;
	while (gameLive)
	{
		gotoxy(75,0);
		cout<<YELLOW<< "���������� �����: "<<coins<<RESET;
		if (Enemy == false) {
			EnemyChans();
		}
		if (_kbhit()) { //���������� ������� ������
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
		Hit(coins); //��������, ����� �� ���� �� ������
		Sleep(45); 
		DeletePlayer(); //������ ������ �� ������� ������������
		deleteEnemy(); //������ �����.
		if (Enemy_position1Y >= 25)  //���� ���� ����� �� ������� �� ������ ��� � ��������� ����.
		{
			Enemy = false;
			coins++;
		}
		else if (Enemy == true && Enemy_position1Y < 25) //���� ������ ����� �� ����� �� ������� �� ����������� ���������� Y ����� �� 1
		{
			Enemy_position1Y++;

		}
	}

} //������ ����� ����




void Menu() {

	system("cls");
	int c = 0;
	int n = 0;
	cout << "====================" << endl;
	cout << "   ����� ���������� �" << endl;
	cout << "       �����" << endl;
	cout << "====================" << endl;
	cout << "\n�������� �����:" << endl;
	cout << BLUE << "1) ����" << endl;
	cout << "2) �������" << endl;
	cout << "3) ����������" << endl;
	cout << "4) �����" << endl;
	cout << RESET << "\n������� ����� �����: ";
	cin >> c;

	switch (c) {
	case 1:

		gameLive = true;
		game();
		break;
	case 2:
		cout << "������� ����:" << endl;
		cout<< "\n�� ��� ���� ����������(������) ���� ������ ���������� �� ��� ��� ����� ������, ������ ������������ - ������ �����" << endl;
		cout << "\n������� 1 ��� �� ��������� ����� � ����" << endl;
		cin >> n;
		if (n == 1) {
			Menu();
		}
		break;
	case 3:

		cout << "����������:" << endl;
		sistings();
		cout << "������� 1 ��� �� ��������� ����� � ����" << endl;

		cin >> n;
		if (n == 1) {
			Menu();
		}
		break;
	case 4:
		cout << "����� �� ����. �� ��������!" << endl;
		Sleep(1000);
		break;
	default:
		
		cout << "�������� �����. ���������� ��� ���." << endl;
		Sleep(1000);
		Menu();
		break;
	}
} //���� ���





int main()
{
	const string filename = "records.txt";
	ifstream fileCheck(filename);
	if (!fileCheck.good()) {
		ofstream createFile(filename);
		createFile.close();
	}
	
	setlocale(LC_ALL, "rus");
	Enemy = true;
	Menu();
	system("cls");
}

