
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Control.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_BN_CLICKED(130, OnButton1Clicked)
	ON_BN_CLICKED(131, OnButton2Clicked)
	ON_BN_CLICKED(132, OnButton3Clicked)
	ON_BN_CLICKED(133, OnButton4Clicked)
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_button1.Create(_T("1번 누를거야?"), WS_CHILD | WS_VISIBLE | BS_PUSHBOX 
		, CRect(100, 100, 230, 130), this, 130);
	m_button2.Create(_T("2번 누를거야?"), WS_CHILD | WS_VISIBLE | BS_PUSHBOX
		, CRect(100, 200, 230, 230), this, 131);
	m_button3.Create(_T("3번 누를거야?"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX
		, CRect(100, 300, 230, 330), this, 132);
	m_button4.Create(_T("4번 누를거야?"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX
		, CRect(100, 400, 230, 430), this, 133);
	

	return 0;
}

void CChildView::OnButton1Clicked()
{
	m_button3.SetCheck(BST_UNCHECKED);
	m_button4.SetCheck(BST_UNCHECKED);
	AfxMessageBox(_T("체크박스를 전부 언체크하다니!"));
}

void CChildView::OnButton2Clicked()
{
	m_button3.SetCheck(BST_CHECKED);
	m_button4.SetCheck(BST_CHECKED);
	AfxMessageBox(_T("체크박스를 전부 체크하다니!"));
}

void CChildView::OnButton3Clicked()
{
	if(m_button3.GetCheck() == BST_UNCHECKED)
	{ 
		m_button3.SetCheck(BST_CHECKED);
		AfxMessageBox(_T("3번을 체크하다니!"));
	}
	else
	{
		m_button3.SetCheck(BST_UNCHECKED);
		AfxMessageBox(_T("3번을 언체크하다니!"));
	}
}

void CChildView::OnButton4Clicked()
{
	if (m_button4.GetCheck() == BST_UNCHECKED)
	{
		m_button4.SetCheck(BST_CHECKED);
		AfxMessageBox(_T("4번을 체크하다니!"));
	}
	else
	{
		m_button4.SetCheck(BST_UNCHECKED);
		AfxMessageBox(_T("4번을 언체크하다니!"));
	}
}
