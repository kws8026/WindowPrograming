
// Midterm_w2.h : Midterm_w2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMidterm_w2App:
// �� Ŭ������ ������ ���ؼ��� Midterm_w2.cpp�� �����Ͻʽÿ�.
//

class CMidterm_w2App : public CWinApp
{
public:
	CMidterm_w2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMidterm_w2App theApp;
