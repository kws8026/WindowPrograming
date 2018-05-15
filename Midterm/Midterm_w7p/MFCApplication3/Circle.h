#pragma once
class CCircle
{
public:
    CCircle();
    CCircle(int _x, int _y) { x= _x; y = _y; v = 0; b= false;};
    ~CCircle();
    int x, y;
    float v;
    bool b;
};

