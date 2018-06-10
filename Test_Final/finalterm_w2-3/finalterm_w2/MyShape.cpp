#include "stdafx.h"
#include "MyShape.h"


MyShape::~MyShape()
{
}

void MyShape::Draw(CDC & dc)
{
	if (IsCircle){
		CBrush brush(RGB(255, 0, 0));
		dc.SelectObject(&brush);
		dc.Ellipse(pos.x - 20, pos.y - 20, pos.x + 20, pos.y + 20);
	}
	else {
		CBrush brush(RGB(0, 0, 255));
		dc.SelectObject(&brush);
		dc.Rectangle(pos.x - 20, pos.y - 20, pos.x + 20, pos.y + 20);
	}
}
