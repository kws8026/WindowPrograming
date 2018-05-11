#include "stdafx.h"
#include "Shape.h"


CShape::CShape() : CShape(0, 0, { 0,0 }, 0)
{
}

CShape::CShape(int s, int b, CPoint p, COLORREF c) : size(s), brush(b), pos(p), color(c)
{
}


CShape::~CShape()
{
}

void CShape::Draw(CDC & dc)
{
	CBrush _brush;
	_brush.CreateSolidBrush(color);
	CPen pen(PS_SOLID,1,color);
	dc.SelectObject(&_brush);
	dc.SelectObject(&pen);
	if (brush == Rect) dc.Rectangle(pos.x - size, pos.y - size, pos.x + size, pos.y + size);
	else if (brush == Circle) dc.Ellipse(pos.x - size, pos.y - size, pos.x + size, pos.y + size);
}

void CShape::SetColor(COLORREF _color)
{
	color = _color;
}
