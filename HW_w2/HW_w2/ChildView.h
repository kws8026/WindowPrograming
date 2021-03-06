
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once
#include "MyShape.h"
#define num 100 
// CChildView 창

class CChildView : public CWnd 
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:
private:
	bool LBClicked;
	bool RBClicked;
	bool DrawPolgon;
	CPoint pMpos;
	CArray<CMyShape*,CMyShape*> ArrShape;
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

