#pragma once
#include "afxwin.h"


// MyDialog 대화 상자입니다.

class MyDialog : public CDialog
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
	CEdit TextBox;
	CEdit ColorBox[3];
	int color[3];
	CString str;
	void MecroColor(COLORREF sourse) 
	{ 
		color[0] = GetRValue(sourse);
		color[1] = GetGValue(sourse);
		color[2] = GetBValue(sourse);
	}
	virtual void OnOK();
	virtual BOOL OnInitDialog();
};
