#pragma once
#include <string>
using namespace std;

class CStudent
{
public:
	CStudent();
	~CStudent();
	CStudent(string _name, string _ID, string _major, string _grade);
public:
	string name, major, ID, grade;
	void ShowData() const;
	void SetInfo(string _name, string _ID, string _major, string _grade);
};

