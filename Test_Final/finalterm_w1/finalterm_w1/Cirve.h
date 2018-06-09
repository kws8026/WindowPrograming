#pragma once
class Cirve
{
	CPoint pos;
	bool IsEnd;
public:
	Cirve() : Cirve(0, false) {}
	Cirve(CPoint p, bool b = false) : pos(p), IsEnd(b) {};
	~Cirve();
	CPoint getPos() { return pos; }
	bool getIsEnd() { return IsEnd; }
};

