
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once
#include "MyShape.h"
#define num 100 
// CChildView â

class CChildView : public CWnd 
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:
private:
	bool LBClicked;
	bool RBClicked;
	bool DrawPolgon;
	CPoint pMpos;
	CArray<CMyShape*,CMyShape*> ArrShape;
// �۾��Դϴ�.
public:

// �������Դϴ�.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// �����Դϴ�.
public:
	virtual ~CChildView();

	// ������ �޽��� �� �Լ�
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

