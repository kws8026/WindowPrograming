#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle()
{
}

CCircle::CCircle(CPoint p, double d)
{
	m_Pos = p;
	m_a = d;
	m_v = 10;
}


CCircle::~CCircle()
{
}

void CCircle::Draw(CPaintDC &dc)
{
	dc.Ellipse(m_Pos.x, m_Pos.y, m_Pos.x + 50, m_Pos.y + 50);;
}

void CCircle::SetYpos(int y)
{
	m_Pos.y = y;
}

void CCircle::AddYpos(int y)
{
	m_Pos.y += y;
}

void CCircle::SetZero()
{
	m_v = 10; m_Pos.y = 0;
}

