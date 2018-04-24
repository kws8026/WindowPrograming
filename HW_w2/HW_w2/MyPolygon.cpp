#include "stdafx.h"
#include "MyPolygon.h"


CMyPolygon::CMyPolygon()
{
}


CMyPolygon::~CMyPolygon()
{
}

void CMyPolygon::draw(CDC & dc)
{
	dc.Polygon(ArrPoint.GetData(), ArrPoint.GetCount());
}

void CMyPolygon::AddPoint(CPoint p)
{
	ArrPoint.Add(p);
}
