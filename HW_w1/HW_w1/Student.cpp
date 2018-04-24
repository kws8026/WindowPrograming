#include "Student.h"
#include <iostream>

CStudent::CStudent()
{
}


CStudent::~CStudent()
{
}

CStudent::CStudent(string _name, string _ID, string _major, string _grade)
{
	name = _name; ID = _ID; major = _major; grade = _grade;
}

void CStudent::ShowData() const
{
	cout << "이름: " << name << '\t' << "학번: " << ID << '\t'<< 
		"학과:" << major << '\t' << "학년 :" << grade << endl;
}

void CStudent::SetInfo(string _name, string _ID, string _major, string _grade)
{
	name = _name; ID = _ID; major = _major; grade = _grade;
}
