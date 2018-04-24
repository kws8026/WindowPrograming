#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle()
{
}

CRectangle::CRectangle(CPoint p1, CPoint p2)
{
	m_pos1 = p1; m_pos2 = p2; Selected = false;
}


CRectangle::~CRectangle()
{
}

void CRectangle::Draw(CDC &dc)
{
	CBrush brush;
	if(Selected)	brush.CreateSolidBrush(RGB(255, 255, 0));
	dc.SelectObject(&brush);
	dc.Rectangle(m_pos1.x, m_pos1.y, m_pos2.x, m_pos2.y);
}

bool CRectangle::PTinRect(CPoint point)
{
	CPoint p1;
	if (m_pos1.x < m_pos2.x) p1.x = m_pos1.x;
	else p1.x = m_pos2.x;
	if (m_pos1.y< m_pos2.y) p1.y = m_pos1.y;
	else p1.y = m_pos2.y;
	CPoint p2;
	if (m_pos1.x > m_pos2.x) p2.x = m_pos1.x;
	else p2.x = m_pos2.x;
	if (m_pos1.y > m_pos2.y) p2.y = m_pos1.y;
	else p2.y = m_pos2.y;
	CRect rect(p1, p2);
	return rect.PtInRect(point);
}

void CRectangle::MovePos(CPoint point)
{
	m_pos1 += point;
	m_pos2 += point;
}


