
// HW_w4.h : HW_w4 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CHW_w4App:
// �� Ŭ������ ������ ���ؼ��� HW_w4.cpp�� �����Ͻʽÿ�.
//

class CHW_w4App : public CWinApp
{
public:
	CHW_w4App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CHW_w4App theApp;
