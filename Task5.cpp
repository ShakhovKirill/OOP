#include <iostream>
#include <vector>

using namespace std;

class base
{
public:
	virtual void show() {};
};

template <typename T> class Point2D
{
protected:
	T x, y;
public:
	Point2D(T x, T y)
	{
		this->x = x;
		this->y = y;
	}
};

template <typename T> class Z
{
protected:
	T z;
public:
	Z(T z)
	{
		this->z = z;
	}
};

template <typename T> class H
{
protected:
	T h;
public:
	H(T h)
	{
		this->h = h;
	}
};

template <typename T> class Point3Dh : public Point2D <T>, Z <T>, H <T>, base {
protected:
	bool flag;
public:
	Point3Dh(T x, T y, T z, T h) : Point2D <T>(x, y), Z <T>(z), H <T>(h) {
		flag = false;
		if (this->h == 0) {
			flag = true;
		}
	}
	void show() {
		if (flag == 0)
		{
			cout << "реальные координаты объекта - " << "(" << this->x / this->h << ", " << this->y / this->h << ", " << this->z / this->h << ")" << endl;
		}
		else {
			cout << "ошибка, 4 координата не должна быть = 0." << endl;
		}
	}
};

int main() {
	setlocale(LC_ALL, "ru");

	Point3Dh <int> point1(7, 6, 6, 7);
	cout << "однородные координаты точки - (6, 7, 6, 7), тип int" << endl;
	point1.show();

	system("pause");
	cout << endl;

	Point3Dh <double> point2(7.717, 6.616, 3.313, 4);
	cout << "однородные координаты точки - (7.717, 6.616, 3.313, 4), double" << endl;
	point2.show();

	system("pause");
	cout << endl;

	Point3Dh <short> point3(23, 23, 7, 7);
	cout << "однородные координаты точки - (23, 23, 7, 7), short." << endl;
	point3.show();

	system("pause");
	cout << endl;

	Point3Dh <long> point4(117, 87, 77, 14);
	cout << "однородные координаты точки - (117, 87, 77, 14), long." << endl;
	point4.show();

	system("pause");
	cout << endl;

	Point3Dh <float> point5(12.7, 9.3, 14.4, 7.7);
	cout << "однородные координаты точки - (12.7, 9.3, 14.4, 7.7), float." << endl;
	point5.show();

	system("pause");
	system("cls");

	vector <base*> v;

	v.push_back((base*)&point1);
	v.push_back((base*)&point2);
	v.push_back((base*)&point3);
	v.push_back((base*)&point4);
	v.push_back((base*)&point5);

	for (int i = 0; i < 5; i++)
	{
		v[i]->show();
	}

	system("pause");
}