
// finalterm_w7.h : finalterm_w7 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cfinalterm_w7App:
// �� Ŭ������ ������ ���ؼ��� finalterm_w7.cpp�� �����Ͻʽÿ�.
//

class Cfinalterm_w7App : public CWinApp
{
public:
	Cfinalterm_w7App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cfinalterm_w7App theApp;
