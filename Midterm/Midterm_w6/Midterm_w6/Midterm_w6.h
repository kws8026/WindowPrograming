
// Midterm_w6.h : Midterm_w6 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMidterm_w6App:
// �� Ŭ������ ������ ���ؼ��� Midterm_w6.cpp�� �����Ͻʽÿ�.
//

class CMidterm_w6App : public CWinApp
{
public:
	CMidterm_w6App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMidterm_w6App theApp;
