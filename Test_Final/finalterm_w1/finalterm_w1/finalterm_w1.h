
// finalterm_w1.h : finalterm_w1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cfinalterm_w1App:
// �� Ŭ������ ������ ���ؼ��� finalterm_w1.cpp�� �����Ͻʽÿ�.
//

class Cfinalterm_w1App : public CWinApp
{
public:
	Cfinalterm_w1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cfinalterm_w1App theApp;
