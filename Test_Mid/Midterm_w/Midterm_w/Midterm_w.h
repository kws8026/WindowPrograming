
// Midterm_w.h : Midterm_w ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMidterm_wApp:
// �� Ŭ������ ������ ���ؼ��� Midterm_w.cpp�� �����Ͻʽÿ�.
//

class CMidterm_wApp : public CWinApp
{
public:
	CMidterm_wApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMidterm_wApp theApp;
