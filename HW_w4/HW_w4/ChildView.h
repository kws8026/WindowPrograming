
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once
#include "Pawn.h"

// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:
	CButton button[5];
	CScrollBar scroll;
private:
	bool played;
	CPoint pos;
	CArray<CPawn, CPawn> arrPawn;
	int Count;
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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void Clear();
	afx_msg void Save();
	afx_msg void Load();
	afx_msg void Play();
	afx_msg void EndPlay();

};

