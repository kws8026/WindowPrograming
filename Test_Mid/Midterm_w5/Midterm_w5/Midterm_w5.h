
// Midterm_w5.h : Midterm_w5 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMidterm_w5App:
// �� Ŭ������ ������ ���ؼ��� Midterm_w5.cpp�� �����Ͻʽÿ�.
//

class CMidterm_w5App : public CWinApp
{
public:
	CMidterm_w5App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMidterm_w5App theApp;
