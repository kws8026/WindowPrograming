
// Midterm_w3.h : Midterm_w3 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMidterm_w3App:
// �� Ŭ������ ������ ���ؼ��� Midterm_w3.cpp�� �����Ͻʽÿ�.
//

class CMidterm_w3App : public CWinApp
{
public:
	CMidterm_w3App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMidterm_w3App theApp;
