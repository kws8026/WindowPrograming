#pragma once
#include "afxwin.h"


// MyDialog ��ȭ �����Դϴ�.

class MyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~MyDialog();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
