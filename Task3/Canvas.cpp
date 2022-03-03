#include "Canvas.h"

void shape::show(HDC hdc) {}

point::point(int x, int y) : x(x), y(y) {}
void point::show(HDC hdc)
{
	SetPixel(hdc, x, y, RGB(255, 255, 255));
}

line::line(int x1, int y1, int x2, int y2) : left(x1, y1), right(x2, y2) {}
void line::show(HDC hdc)
{
	SelectObject(hdc, GetStockObject(WHITE_PEN));
	MoveToEx(hdc, left.x, left.y, 0);
	LineTo(hdc, right.x, right.y);
}

rectangle::rectangle(int x1, int y1, int x2, int y2, COLORREF c, bool filled, COLORREF bc) :
	top_left(x1, y1), bottom_right(x2, y2), color(c), filled(filled), background_color(bc) {}
void rectangle::show(HDC hdc)
{
	SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
	SetDCPenColor(hdc, color); // установка цвета контура фигуры
	SetDCBrushColor(hdc, background_color); // установка цвета закраски
	if (filled)
	{
		SelectObject(hdc, GetStockObject(DC_BRUSH)); // выбор стандартной кисти
	}
	else
	{
		SelectObject(hdc, GetStockObject(NULL_BRUSH)); // отключение закраски
	}
	Rectangle(hdc, top_left.x, top_left.y, bottom_right.x, bottom_right.y);
}

ellipse::ellipse(int x1, int y1, int x2, int y2, COLORREF c, bool filled, COLORREF bc) :
	top_left(x1, y1), bottom_right(x2, y2), color(c), background_color(bc), filled(filled) {}
void ellipse::show(HDC hdc)
{
	SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
	SetDCPenColor(hdc, color); // установка цвета контура фигуры
	SetDCBrushColor(hdc, background_color); // установка цвета закраски
	if (filled)
	{
		SelectObject(hdc, GetStockObject(DC_BRUSH)); // выбор стандартной кисти
	}
	else
	{
		SelectObject(hdc, GetStockObject(NULL_BRUSH)); // отключение закраски
	}
	Ellipse(hdc, top_left.x, top_left.y, bottom_right.x, bottom_right.y);
}

polygon::polygon(int n, COLORREF c, const POINT Points[6], bool filled, COLORREF bc) :
	cPoints(n), lppt{ Points }, color(c), background_color(bc), filled(filled) {}
void polygon::show(HDC hdc)
{
	SelectObject(hdc, GetStockObject(DC_PEN)); // выбор стандартного пера
	SetDCPenColor(hdc, color); // установка цвета контура фигуры
	SetDCBrushColor(hdc, background_color); // установка цвета закраски
	if (filled)
	{
		SelectObject(hdc, GetStockObject(DC_BRUSH)); // выбор стандартной кисти
	}
	else
	{
		SelectObject(hdc, GetStockObject(NULL_BRUSH)); // отключение закраски
	}
	Polygon(hdc, lppt, cPoints);
}

canvas::canvas()
{
	hWnd = GetConsoleWindow(); // ссылка на окно
	hdc = GetDC(hWnd);		// ссылка на контекст устройства графического вывода
}

canvas::~canvas()
{
	ReleaseDC(hWnd, hdc);
}

void canvas::add(shape* s)
{
	figures.push_back(s);
}

void canvas::clear()
{
	figures.clear();
}

void canvas::show()
{
	for (size_t i = 0; i < figures.size(); i++)
		figures[i]->show(hdc);
}