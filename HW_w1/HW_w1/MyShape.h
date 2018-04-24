#pragma once
class CMyShape
{
public:
	CMyShape();
	CMyShape(int _x, int _y);
	~CMyShape();
public:
	int x = 0, y = 0;
	virtual void draw() const;
};

