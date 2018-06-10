
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "finalterm_w4.h"
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
	ON_BN_CLICKED(130,OnClicked)
	ON_BN_CLICKED(131, OnClicked)
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
	CRect rect;
	CBitmap bitmap;
	GetClientRect(rect);
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bitmap);
	memDC.FillRect(rect, WHITE_BRUSH);

	if (Radio[0].GetCheck() == BST_CHECKED)
		memDC.Ellipse(50, 50, rect.Width() - 50, rect.Height() - 50);
	else
		memDC.Rectangle(50, 50, rect.Width() - 50, rect.Height() - 50);

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	Radio[0].Create(_T("��"), BS_AUTORADIOBUTTON | WS_VISIBLE, CRect(0, 0, 100, 30), this, 130);
	Radio[1].Create(_T("�簢��"), BS_AUTORADIOBUTTON | WS_VISIBLE, CRect(0, 30, 100, 60), this, 131);
	Radio[0].SetCheck(BST_CHECKED);
	return 0;
}

void CChildView::OnClicked()
{
	Invalidate();
}
