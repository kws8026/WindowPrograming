
// Mideterm_w4.h : Mideterm_w4 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMideterm_w4App:
// �� Ŭ������ ������ ���ؼ��� Mideterm_w4.cpp�� �����Ͻʽÿ�.
//

class CMideterm_w4App : public CWinApp
{
public:
	CMideterm_w4App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMideterm_w4App theApp;
