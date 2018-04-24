
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "Midterm_w.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	LBClicked = false; RBClicked = false; m_PosP = NULL;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
ON_WM_MOUSEMOVE()
ON_WM_RBUTTONDOWN()
ON_WM_RBUTTONUP()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
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
	for(int i = 0; i < Dot.GetCount(); i++)
	{ 
		dc.SetPixel(Dot[i],RGB(0,0,0));
	}
	CString str;
	str.Format(_T("%d"), Dot.GetCount());
	dc.TextOut(10, 10, str);
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(LBClicked)
	{ 
		Dot.Add(point);
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (LBClicked) return;
	GetCapture();
	RBClicked = true;
	m_PosP = point;
	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (!RBClicked) return;
	ReleaseCapture();
	CPoint p1;
	if (m_PosP.x < point.x) p1.x = m_PosP.x;
	else p1.x = point.x;
	if (m_PosP.y< point.y) p1.y = m_PosP.y;
	else p1.y = point.y;
	CPoint p2;
	if (m_PosP.x > point.x) p2.x = m_PosP.x;
	else p2.x = point.x;
	if (m_PosP.y > point.y) p2.y = m_PosP.y;
	else p2.y = point.y;
	CRect rect(p1,p2);
	for (int i = Dot.GetSize() -1; i >= 0; i--)
	{
		if ( rect.PtInRect(Dot[i]) )
		{
			Dot.RemoveAt(i);
		}
	}
	RBClicked = false;
	Invalidate();
	CWnd::OnRButtonUp(nFlags, point);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (RBClicked) return;
	GetCapture();
	LBClicked = true;
	Dot.Add(point);
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (!LBClicked) return;
	ReleaseCapture();
	Dot.Add(point);
	LBClicked = false;
	Invalidate();
	CWnd::OnLButtonUp(nFlags, point);
}
