
// MFCApplication4.h : MFCApplication4 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFCApplication4App:
// �� Ŭ������ ������ ���ؼ��� MFCApplication4.cpp�� �����Ͻʽÿ�.
//

class CMFCApplication4App : public CWinApp
{
public:
	CMFCApplication4App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication4App theApp;
