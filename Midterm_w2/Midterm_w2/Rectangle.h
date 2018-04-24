#pragma once
class CRectangle
{
public:
	CRectangle();
	CRectangle(CPoint p1, CPoint p2);
	~CRectangle();
private:
	CPoint m_pos1;
	CPoint m_pos2;
	int m_Color;
public:
	void Draw(CDC &dc);
	void SetColor(int color);
};

