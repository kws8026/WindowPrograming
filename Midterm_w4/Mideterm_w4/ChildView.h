
// ChildView.h : CChildView 클래스의 인터페이스
//


#pragma once


// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:

// 작업입니다.
public:
private:
	CString str;
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
//	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
//	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

