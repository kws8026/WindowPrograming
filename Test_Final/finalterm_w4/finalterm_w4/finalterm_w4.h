
// finalterm_w4.h : finalterm_w4 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cfinalterm_w4App:
// �� Ŭ������ ������ ���ؼ��� finalterm_w4.cpp�� �����Ͻʽÿ�.
//

class Cfinalterm_w4App : public CWinApp
{
public:
	Cfinalterm_w4App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cfinalterm_w4App theApp;
