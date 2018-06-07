#pragma once
#include "afxwin.h"
class CChildView;

// MyDialogEx 대화 상자입니다.

class MyDialogEx : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialogEx)

public:
	MyDialogEx(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~MyDialogEx();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CChildView *pView;
	CEdit TextBox;
	CButton Radio[3];
	CString str;
	COLORREF color;

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

};
