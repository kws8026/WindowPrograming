#include "stdafx.h"
#include "MyCircle.h"


CMyCircle::CMyCircle()
{
}


CMyCircle::~CMyCircle()
{
}

void CMyCircle::draw(CDC  &dc)
{
	dc.Ellipse(LTpos.x, LTpos.y, RBpos.x , RBpos.y);
}
