
// Midterm_w8.h : Midterm_w8 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMidterm_w8App:
// �� Ŭ������ ������ ���ؼ��� Midterm_w8.cpp�� �����Ͻʽÿ�.
//

class CMidterm_w8App : public CWinApp
{
public:
	CMidterm_w8App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMidterm_w8App theApp;
