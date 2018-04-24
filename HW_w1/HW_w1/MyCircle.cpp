#include "MyCircle.h"
#include <iostream>
using namespace std;

CMyCircle::CMyCircle()
{
}


CMyCircle::~CMyCircle()
{
}

CMyCircle::CMyCircle(int _x, int _y, int _r)
{
	x = _x; y = _y; r = _r;
}

void CMyCircle::draw() const
{
	cout << "[MyRect] (" << x << ',' << y << ") r:" << r << endl;
}
