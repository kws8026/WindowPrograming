#pragma once
#include "MyShape.h"
class CMyCircle :
	public CMyShape
{
public:
	CMyCircle();
	~CMyCircle();
	CMyCircle(int _x, int _y, int _r);
public:
	int r = 0;
	virtual void draw() const;
};

