
// Midterm_w7.h : Midterm_w7 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMidterm_w7App:
// �� Ŭ������ ������ ���ؼ��� Midterm_w7.cpp�� �����Ͻʽÿ�.
//

class CMidterm_w7App : public CWinApp
{
public:
	CMidterm_w7App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMidterm_w7App theApp;
