
// HW_w2.h : HW_w2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CHW_w2App:
// �� Ŭ������ ������ ���ؼ��� HW_w2.cpp�� �����Ͻʽÿ�.
//

class CHW_w2App : public CWinApp
{
public:
	CHW_w2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHW_w2App theApp;
