#include "MyPoint.h"
#include <Cmath>
#include <iostream>
using namespace std;


CMyPoint::CMyPoint()
{
	x = 0; y = 0;
}

CMyPoint::CMyPoint(int _x, int _y)
{
	x = _x; y = _y;
}


CMyPoint::~CMyPoint()
{
}

void CMyPoint::print() const
{
	cout << '(' << x << ',' << y << ')' << endl;
}

double CMyPoint::distance(CMyPoint a) const
{
	return sqrt(pow(x - a.x, 2) + pow(y - a.y, 2));
}
