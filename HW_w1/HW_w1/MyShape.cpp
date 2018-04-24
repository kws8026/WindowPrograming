#include "MyShape.h"
#include <iostream>
using namespace std;

CMyShape::CMyShape()
{
}

CMyShape::CMyShape(int _x, int _y)
{
	x = _x; y = _y;
}


CMyShape::~CMyShape()
{
}

void CMyShape::draw() const
{
	cout << "[MyShape] (" << x << ',' << y << ')' << endl;
}
