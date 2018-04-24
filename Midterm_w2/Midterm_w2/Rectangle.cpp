#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle()
{
	m_Color = 1;
}

CRectangle::CRectangle(CPoint p1, CPoint p2)
{
	m_pos1 = p1; m_pos2 = p2; m_Color = 1;
}


CRectangle::~CRectangle()
{
}

void CRectangle::Draw(CDC &dc)
{
	CBrush brush;
		switch (m_Color)
		{
		case 1:
			brush.CreateSolidBrush(RGB(255, 0, 0));
			break;
		case 2:
			brush.CreateSolidBrush(RGB(0, 255, 0));
			break;
		case 3:
			brush.CreateSolidBrush(RGB(0, 0, 255));
			break;
		default:
			return;
		}
	dc.SelectObject(&brush);
	dc.Rectangle(m_pos1.x,m_pos1.y, m_pos2.x, m_pos2.y);
}

void CRectangle::SetColor(int color)
{
	m_Color = color;
}
