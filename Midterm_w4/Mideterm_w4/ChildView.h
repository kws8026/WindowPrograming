
// ChildView.h : CChildView Ŭ������ �������̽�
//


#pragma once


// CChildView â

class CChildView : public CWnd
{
// �����Դϴ�.
public:
	CChildView();

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:
private:
	CString str;
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
//	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
//	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};
