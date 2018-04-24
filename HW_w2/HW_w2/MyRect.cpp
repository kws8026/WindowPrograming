#include "stdafx.h"
#include "MyRect.h"
#define IDB_BITMAP2 311
CMyRect::CMyRect()
{
}

CMyRect::~CMyRect()
{
}

void CMyRect::draw(CDC  &dc)
{
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP2);
	CDC memDc;
	memDc.CreateCompatibleDC(&dc);
	memDc.SelectObject(&bmp);
	
	dc.StretchBlt(LTpos.x, LTpos.y,RBpos.x - LTpos.x,RBpos.y- LTpos.y, &memDc, 0, 0, 100, 100, SRCCOPY);
}
