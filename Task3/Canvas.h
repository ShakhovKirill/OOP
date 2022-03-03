#pragma once
using namespace std;
#ifndef CANVAS_H
#include <vector>
#include <conio.h>
#include <windows.h>
#define CANVAS_H


class shape {
public:
	virtual void show(HDC hdc); // виртуальный метод, позволяющий использовать метод show конкретного класса
}; // базовый класс для фигур

class point : shape {
public:
	int x, y;
	COLORREF color;
	point(int x, int y);
	void show(HDC hdc);
};

class line : shape {
	point left;
	point right;
public:
	line(int x1, int y1, int x2, int y2);
	void show(HDC hdc);
};

class rectangle : shape {
	point top_left;
	point bottom_right;
	COLORREF color;
	COLORREF background_color;
	bool filled;
public:
	rectangle(int x1, int y1, int x2, int y2, COLORREF c, bool filled, COLORREF bc);
	void show(HDC hdc);
};

class ellipse : shape
{
	point top_left;
	point bottom_right;
	COLORREF color;
	COLORREF background_color;
	bool filled;
public:
	ellipse(int x1, int y1, int x2, int y2, COLORREF c, bool filled, COLORREF bc);
	void show(HDC hdc);
};

class polygon : shape
{
	int cPoints;
	const POINT* lppt;
	COLORREF color;
	COLORREF background_color;
	bool filled;
public:
	polygon(int n, COLORREF c, const POINT Points[6], bool filled, COLORREF bc);
	void show(HDC hdc);
};

class canvas
{
	vector <shape*> figures;
	HWND hWnd;
	HDC hdc;
public:
	canvas();
	~canvas();
	void add(shape* s);
	void clear();
	void show();
};

#endif
