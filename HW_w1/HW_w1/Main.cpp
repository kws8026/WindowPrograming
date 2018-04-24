#include "Student.h"
#include "MyPoint.h"
#include "MyTime.h"
#include "MyCircle.h"
#include "MyRect.h"
#include "MyShape.h"
#include <iostream>
using namespace std;

void Fnc(int Hd)
{
	if (Hd == 1)
	{
		CStudent s("Lee min su", "10010", "Elect", "2");
		s.ShowData();
		CStudent _s[3];
		string str[12];
		for (int i = 0; i < 3; i++)
		{
			cout << "이름 :";
			cin >> str[i * 4];
			cout << "학번 :";
			cin >> str[(i * 4) + 1];
			cout << "전공 :";
			cin >> str[(i * 4) + 2];
			cout << "학년 :";
			cin >> str[(i * 4) + 3];
			_s[i].SetInfo(str[i * 4], str[(i * 4) + 1], str[(i * 4) + 2], str[(i * 4) + 3]);
			// _s[i].name = str[i*4]; _s[i].ID = str[(i*4)+1]; _s[i].major = str[(i*4)+2]; _s[i].grade = str[(i*4)+3];
		}
		for (int i = 0; i < 3; i++)
		{
			_s[i].ShowData();
		}
		/*
		CStudent* _s[3];
		string str[12];
		for (int i = 0; i < 3; i++)
		{
			cout << "이름 :";
			cin >> str[i * 4];
			cout << "학번 :";
			cin >> str[(i * 4) + 1];
			cout << "전공 :";
			cin >> str[(i * 4) + 2];
			cout << "학년 :";
			cin >> str[(i * 4) + 3];
			_s[i] = new CStudent(str[i * 4], str[(i * 4) + 1], str[(i * 4) + 2], str[(i * 4) + 3]);
		}
		for (int i = 0; i < 3; i++)
		{
			_s[i]->ShowData();
			delete _s[i];
		}
		*/
	}
	else if (Hd == 2) 
	{
		CMyPoint a(4, 5);
		CMyPoint b(1, 1);
		a.print();
		b.print();
		cout << "a와 b의 거리 : " << a.distance(b) << endl;
	}
	else if (Hd == 3)
	{
		CMyTime a(0, 70, 90);
		CMyTime b(0, 0, 3630);
		a.print();
		b.print();
		a.add(b);
		a.print();
	}
	else if (Hd == 4)
	{
		CMyShape * pShape1 = new CMyShape(10, 3);
		CMyShape * pShape2 = new CMyRect(3, 5, 7, 8);
		CMyShape * pShape3 = new CMyCircle(4, 5, 1);
		pShape1->draw();
		pShape2->draw();
		pShape3->draw();
		delete pShape1;
		delete pShape2;
		delete pShape3;
	}
}

int main(void) 
{
	int num = 0;
	while(num != 5){
		cout << "1. Student 2. Point 3. Time 4. Shape 5. Exit" << endl << "Input :";
		cin >> num;
		Fnc(num);
	}
	return 0;
}

/*
int main(void)
{
	CStudent s("Lee min su", "10010", "Elect", "2");
	s.ShowData();

	CStudent _s[3];
	string str[12];
	for (int i = 0; i < 12; i ++) 
	{
		cin >> str[i];
		if (i % 4 == 3)
		{
			_s[(i+1)/4-1].SetInfo(str[i - 3], str[i - 2], str[i - 1], str[i]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		_s[i].ShowData();
	}

	return 0;
}
*/
/*
int main()
{
	CMyPoint a(4, 5);
	CMyPoint b(1, 1);
	a.print();
	b.print();
	cout << "a ¿Í bÀÇ °Å¸® : " << a.distance(b) << endl;
	return 0;
}
*/
/*
int main()
{
	CMyTime a(0, 70, 90);
	CMyTime b(0, 0, 3630);
	a.print();
	b.print();
	a.add(b);
	a.print();
	return 0;
}
*/
/*
int main()
{
	CMyShape * pShape1 = new CMyShape(10, 3);
	CMyShape * pShape2 = new CMyRect(3, 5, 7, 8);
	CMyShape * pShape3 = new CMyCircle(4, 5, 1);
	pShape1->draw();
	pShape2->draw();
	pShape3->draw();
	delete pShape1;
	delete pShape2;
	delete pShape3;
	return 0;
}
*/