
// Practice.h : Practice ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CPracticeApp:
// �� Ŭ������ ������ ���ؼ��� Practice.cpp�� �����Ͻʽÿ�.
//

class CPracticeApp : public CWinApp
{
public:
	CPracticeApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CPracticeApp theApp;
