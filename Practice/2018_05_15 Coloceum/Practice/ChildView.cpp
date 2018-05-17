
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "Practice.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView() :CamPos(1000,500)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
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
	CDC memDC;
	CBitmap bitmap;
	CRect rect;
	CRect memRect;
	GetClientRect(rect);
	memRect = { 0,0,rect.Width() * 3,rect.Height() * 3};
	bitmap.CreateCompatibleBitmap(&dc, memRect.Width(), memRect.Height());
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bitmap);
	memDC.FillRect(memRect,WHITE_BRUSH);


	
	dc.BitBlt(0, 0, rect.Width(), rect.Height(),&memDC, CamPos.x, CamPos.y,SRCCOPY);
	
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nChar == 'W' || nChar == VK_UP)
	{

	}
	if (nChar == 'D' || nChar == VK_DOWN)
	{

	}
	if (nChar == 'A' || nChar == VK_LEFT)
	{

	}
	if (nChar == 'D' || nChar == VK_RIGHT)
	{

	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CWnd::OnTimer(nIDEvent);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CWnd::OnMouseMove(nFlags, point);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}
