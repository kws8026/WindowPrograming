
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once
#include "Pawn.h"

// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:
	CButton button[5];
	CScrollBar scroll;
private:
	bool played;
	CPoint pos;
	CArray<CPawn, CPawn> arrPawn;
	int Count;
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

