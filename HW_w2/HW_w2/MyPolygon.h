#pragma once
#include "MyShape.h"
class CMyPolygon:
	public CMyShape
{
public:
	CMyPolygon();
	~CMyPolygon();
private:
	CArray<CPoint, CPoint> ArrPoint;
public:
	void draw(CDC  &dc);
	void AddPoint(CPoint p);
};

