
// HW_w3.h : HW_w3 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CHW_w3App:
// �� Ŭ������ ������ ���ؼ��� HW_w3.cpp�� �����Ͻʽÿ�.
//

class CHW_w3App : public CWinApp
{
public:
	CHW_w3App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHW_w3App theApp;
