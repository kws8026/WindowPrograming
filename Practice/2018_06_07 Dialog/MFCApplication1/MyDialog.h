#pragma once
#include "afxwin.h"


// MyDialog ��ȭ �����Դϴ�.

class MyDialog : public CDialog
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
	afx_msg void OnEnChangeEdit1();
	CEdit TextBox;
	CButton Radio[3];
	CString str;
	COLORREF color;
	virtual void OnOK();
	virtual BOOL OnInitDialog();
};
