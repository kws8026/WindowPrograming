
// 2018_05_17 Diglog.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMy2018_05_17DiglogApp:
// �� Ŭ������ ������ ���ؼ��� 2018_05_17 Diglog.cpp�� �����Ͻʽÿ�.
//

class CMy2018_05_17DiglogApp : public CWinApp
{
public:
	CMy2018_05_17DiglogApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMy2018_05_17DiglogApp theApp;