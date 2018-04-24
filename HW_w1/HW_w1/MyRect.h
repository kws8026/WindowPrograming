#pragma once
#include "MyShape.h"
class CMyRect :
	public CMyShape
{
public:
	CMyRect(); 
	CMyRect(int _x, int _y, int _w, int _h);
	~CMyRect();
public:
	int w = 0, h = 0;
	virtual void draw() const;
};

