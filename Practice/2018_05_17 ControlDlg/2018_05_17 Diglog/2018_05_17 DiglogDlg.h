
// 2018_05_17 DiglogDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CMy2018_05_17DiglogDlg ��ȭ ����
class CMy2018_05_17DiglogDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy2018_05_17DiglogDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY2018_05_17DIGLOG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_PB1;
	CButton m_PB2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
