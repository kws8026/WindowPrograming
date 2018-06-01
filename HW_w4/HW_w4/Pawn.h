#pragma once
class CPawn
{
	CPoint pos;
	bool isCircle;
public:
	CPawn() {};
	CPawn(CPoint p, bool c=0):pos(p), isCircle(c) {};
	~CPawn();
	CPoint getPos() { return pos; }
	bool getIsCircle() { return isCircle; }
	void Draw(CDC &dc);
};

