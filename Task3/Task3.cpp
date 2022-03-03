#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <iostream>


#include "Canvas.h"

using namespace std;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем генерацию значения из диапазона
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}



int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "клавиша p - точка" << endl;
	cout << "клавиша l - отрезок" << endl;
	cout << "клавиша r - прямоугольник" << endl;
	cout << "клавиша e - эллипс" << endl;
	cout << "клавиша a - многоугольник" << endl;
	cout << "клавиша q - завершение работы" << endl;
	srand(static_cast<unsigned int>(time(0)));
	rand();

	canvas c;

	char x = ' ';
	while (x != 'q')
	{
		c.clear();
		x = _getch();
		switch (x)
		{
		case 'p':
			c.add((shape*)new point(250, 250));
			c.show();
			break;
		case 'l':
			c.add((shape*)new line(10, 300, 200, 300));
			c.show();
			break;
		case 'r':
			c.add((shape*)new rectangle(100, 100, 200, 200, RGB(getRandomNumber(0, 255), getRandomNumber(0, 255), getRandomNumber(0, 255)), true, RGB(getRandomNumber(0, 255), getRandomNumber(0, 255), getRandomNumber(0, 255))));
			c.show();
			break;
		case 'e':
			c.add((shape*)new ellipse(250, 100, 450, 200, RGB(getRandomNumber(0, 255), getRandomNumber(0, 255), getRandomNumber(0, 255)), true, RGB(getRandomNumber(0, 255), getRandomNumber(0, 255), getRandomNumber(0, 255))));
			c.show();
			break;
		case 'a':
			POINT pp[6];  //объявляем 6 структур POINT для хранения координат
			pp[0].x = 600; pp[0].y = 50;  //заполняем
			pp[1].x = 650; pp[1].y = 100;
			pp[2].x = 650; pp[2].y = 150;
			pp[3].x = 600; pp[3].y = 200;
			pp[4].x = 550;  pp[4].y = 150;
			pp[5].x = 550;  pp[5].y = 100;
			c.add((shape*)new polygon(6, RGB(getRandomNumber(0, 255), getRandomNumber(0, 255), getRandomNumber(0, 255)), pp, true, RGB(getRandomNumber(0, 255), getRandomNumber(0, 255), getRandomNumber(0, 255))));
			c.show();
			break;
		default:
			break;
		}
	}


	return 0;
}