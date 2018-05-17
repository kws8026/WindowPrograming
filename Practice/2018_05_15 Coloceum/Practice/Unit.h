#pragma once
class CUnit
{
	int m_Hp, m_Armor;
	CPoint m_Pos;
public:
	CUnit() : CUnit(0, 0, {0,0}) {};
	CUnit(int hp, int armor, CPoint point) :m_Hp(hp), m_Armor(armor), m_Pos(point) {};
	~CUnit();
};

