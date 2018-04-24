#pragma once
class CRectangle
{
	public:
		CRectangle();
		CRectangle(CPoint p1, CPoint p2);
		~CRectangle();
	private:
		CPoint m_pos1;
		CPoint m_pos2;
		bool Selected;
	public:
		void Draw(CDC &dc);
		bool PTinRect(CPoint point);
		void MovePos(CPoint point);
		void SetSelected(bool b) {Selected = b;};
};