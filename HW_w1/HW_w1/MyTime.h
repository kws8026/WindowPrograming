#pragma once
class CMyTime
{
public:
	CMyTime();
	CMyTime(int h, int m, int s);
	~CMyTime();
public:
	int hour = 0, minute = 0, second = 0;
	void print() const;
	void add(CMyTime a);
};

