
// finalterm_w5.h : finalterm_w5 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cfinalterm_w5App:
// �� Ŭ������ ������ ���ؼ��� finalterm_w5.cpp�� �����Ͻʽÿ�.
//

class Cfinalterm_w5App : public CWinApp
{
public:
	Cfinalterm_w5App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cfinalterm_w5App theApp;
