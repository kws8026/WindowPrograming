#pragma once
#define Rect 0
#define Circle 1

class CShape
{
	int size;
	int brush;
	COLORREF color;
	CPoint pos;
public:
	CShape();
	CShape(int s, int b, CPoint p, COLORREF c);
	~CShape();
	void Draw(CDC &dc);
	void SetColor(COLORREF _color);
	CPoint GetPos() { return pos; }
};

