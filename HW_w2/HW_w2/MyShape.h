#pragma once
class CMyShape
{
public:
	CMyShape();
	~CMyShape();
protected:
	CPoint LTpos, RBpos;
public:
	virtual void draw(CDC &dc) {};
	virtual void AddPoint (CPoint p) {};
	void SetPoint(CPoint p1, CPoint p2) { LTpos = p1;  RBpos = p2; }
};

