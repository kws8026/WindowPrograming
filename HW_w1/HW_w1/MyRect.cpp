#include "MyRect.h"
#include <iostream>
using namespace std;

CMyRect::CMyRect()
{
}

CMyRect::CMyRect(int _x, int _y, int _w, int _h)
{
	x = _x; y = _y; w = _w; h = _h;
}


CMyRect::~CMyRect()
{
}

void CMyRect::draw() const
{
	cout << "[MyRect] (" << x << ',' << y << ") w:" << w << " h:" << h << endl;
}
