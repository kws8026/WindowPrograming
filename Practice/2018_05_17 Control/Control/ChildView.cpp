
// ChildView.cpp : CChildView Ŭ������ ����
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



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	m_button1.Create(_T("1�� �����ž�?"), WS_CHILD | WS_VISIBLE | BS_PUSHBOX 
		, CRect(100, 100, 230, 130), this, 130);
	m_button2.Create(_T("2�� �����ž�?"), WS_CHILD | WS_VISIBLE | BS_PUSHBOX
		, CRect(100, 200, 230, 230), this, 131);
	m_button3.Create(_T("3�� �����ž�?"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX
		, CRect(100, 300, 230, 330), this, 132);
	m_button4.Create(_T("4�� �����ž�?"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX
		, CRect(100, 400, 230, 430), this, 133);
	

	return 0;
}

void CChildView::OnButton1Clicked()
{
	m_button3.SetCheck(BST_UNCHECKED);
	m_button4.SetCheck(BST_UNCHECKED);
	AfxMessageBox(_T("üũ�ڽ��� ���� ��üũ�ϴٴ�!"));
}

void CChildView::OnButton2Clicked()
{
	m_button3.SetCheck(BST_CHECKED);
	m_button4.SetCheck(BST_CHECKED);
	AfxMessageBox(_T("üũ�ڽ��� ���� üũ�ϴٴ�!"));
}

void CChildView::OnButton3Clicked()
{
	if(m_button3.GetCheck() == BST_UNCHECKED)
	{ 
		m_button3.SetCheck(BST_CHECKED);
		AfxMessageBox(_T("3���� üũ�ϴٴ�!"));
	}
	else
	{
		m_button3.SetCheck(BST_UNCHECKED);
		AfxMessageBox(_T("3���� ��üũ�ϴٴ�!"));
	}
}

void CChildView::OnButton4Clicked()
{
	if (m_button4.GetCheck() == BST_UNCHECKED)
	{
		m_button4.SetCheck(BST_CHECKED);
		AfxMessageBox(_T("4���� üũ�ϴٴ�!"));
	}
	else
	{
		m_button4.SetCheck(BST_UNCHECKED);
		AfxMessageBox(_T("4���� ��üũ�ϴٴ�!"));
	}
}
