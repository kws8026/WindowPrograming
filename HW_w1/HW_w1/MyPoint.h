#pragma once
class CMyPoint
{
public:
	CMyPoint();
	CMyPoint(int _x, int _y);
	~CMyPoint();
public:
	int x, y;
	void print() const;
	double distance(CMyPoint a) const;
};

