#pragma once
class CCircle
{
public:
	CCircle();
	CCircle(CPoint p,double d);
	~CCircle();
private:
	CPoint m_Pos;
	double m_a;
	float m_v;
public:
	void Draw(CPaintDC &dc);
	double GetA() { return m_a; };
	float GetV() { return m_v; };
	int GetYpos() { return m_Pos.y; };
	void SetYpos(int y);
	void SetV(float v) { m_v = v; };
	void AddV(float v) { m_v += v; };
	void AddYpos(int y);
	void SetZero();
};

