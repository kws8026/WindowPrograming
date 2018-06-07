#pragma once
#include "afxwin.h"
class CChildView;

// MyDialogEx ��ȭ �����Դϴ�.

class MyDialogEx : public CDialogEx
{
	DECLARE_DYNAMIC(MyDialogEx)

public:
	MyDialogEx(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~MyDialogEx();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
