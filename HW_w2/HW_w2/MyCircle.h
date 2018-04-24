#pragma once
#include "MyShape.h"
class CMyCircle :
	public CMyShape
{
public:
	CMyCircle();
	~CMyCircle();
	void draw(CDC  &dc);
};

