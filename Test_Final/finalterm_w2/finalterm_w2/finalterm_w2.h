
// finalterm_w2.h : finalterm_w2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cfinalterm_w2App:
// �� Ŭ������ ������ ���ؼ��� finalterm_w2.cpp�� �����Ͻʽÿ�.
//

class Cfinalterm_w2App : public CWinApp
{
public:
	Cfinalterm_w2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cfinalterm_w2App theApp;
