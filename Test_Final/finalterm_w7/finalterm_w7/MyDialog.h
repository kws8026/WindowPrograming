#pragma once
#include "afxwin.h"


// MyDialog 대화 상자입니다.

class MyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~MyDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CButton Number[10];
	class CChildView* viewptr;
	CString* strptr;
	afx_msg void OnBnClickedPlus();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMltip();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedEND();
	afx_msg void OnBnClickedCLEAR();
	afx_msg void OnBnClickedBackspace();
	afx_msg void OnBnClickedNumber(UINT id);
};
