#pragma once
#include "MyShape.h"
class CMyRect :
	public CMyShape
{
public:
	CMyRect();
	~CMyRect();
	void draw(CDC  &dc);
};

