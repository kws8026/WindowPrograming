#include "MyTime.h"
#include <iostream>
using namespace std;

CMyTime::CMyTime()
{
}

CMyTime::CMyTime(int h, int m, int s)
{
	while (s >= 60)
	{
		s -= 60;
		m++;
	}
	while (m >= 60)
	{
		m -= 60;
		h++;
	}
	hour = h;
	minute = m;
	second = s;
}


CMyTime::~CMyTime()
{
}

void CMyTime::print() const
{
	if (hour < 10)
	{
		cout << '0';
	}
	cout << hour << ':'; 
	if (minute < 10)
	{
		cout << '0';
	}
	cout << minute << ':';
	if (second < 10)
	{
		cout << '0';
	}
	cout << second << endl;
}

void CMyTime::add(CMyTime a)
{
	hour += a.hour; minute += a.minute; second += a.second;
	while (second >= 60)
	{
		second -= 60;
		minute++;
	}
	while (minute >= 60)
	{
		minute -= 60;
		hour++;
	}
}
