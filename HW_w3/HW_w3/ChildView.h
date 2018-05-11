
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once
#include "Shape.h"

// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:
	CList<CShape> ShapeList;
	CPoint m_point;
	COLORREF m_color;
	int m_brush;
	bool Eraser;
	bool Animation;
	int EraserSize[2];
	int m_Vx, m_Vy;
// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBSRectangle() { m_brush = Rect; };
	afx_msg void OnBSCircle() { m_brush = Circle; };
	afx_msg void OnAnimation()
	{
		m_Vx = 0; m_Vy = 0;
		if(Eraser == true && Animation != true) Animation = true; 
		else if (Animation) Animation = false;
	};
	afx_msg void OnBlack() { m_color = RGB(0, 0, 0); }
	afx_msg void OnRed() { m_color = RGB(255, 0, 0); }
	afx_msg void OnBlue() { m_color = RGB(0, 0, 255); }
	afx_msg void OnGreen() { m_color = RGB(0, 255, 0); }
	afx_msg void OnUpdateAnimation(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRectangle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateCircle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBlack(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRed(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateBlue(CCmdUI* pCmdUI);
};

