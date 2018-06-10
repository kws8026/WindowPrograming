#pragma once
class MyShape
{
	CPoint pos;
	bool IsCircle;
public:
	MyShape() : MyShape(0, 0) {}
	MyShape(CPoint p, bool b = true) :pos(p), IsCircle(b) {}
	~MyShape();

	void Draw(CDC &dc);
};

