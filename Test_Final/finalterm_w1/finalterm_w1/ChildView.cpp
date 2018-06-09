
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "finalterm_w1.h"
#include "ChildView.h"
#include "Cirve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView() : IsClicked(false), IsDelete(false)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
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
	GetClientRect(rect);
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bitmap);
	memDC.FillRect(rect,WHITE_BRUSH);

	for (int i = 0; i < cirve.GetCount(); i++)
	{
		if (cirve[i].getIsEnd())
			memDC.MoveTo(cirve[i].getPos());
		else
			memDC.LineTo(cirve[i].getPos());
	}

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (IsDelete) return;
	if (!IsClicked) IsClicked = true;
	cirve.Add({ point,true });
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (IsDelete) return;
	if (IsClicked) {
		cirve.Add({ point,true });
		IsClicked = false;
	}
	Invalidate();
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (IsDelete) return;
	if(IsClicked){
		cirve.Add(point);
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (!IsDelete){
		IsDelete = true;
		SetTimer(0, 100, NULL);
	}
	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == 0 && IsDelete == true)
	{
		if(cirve.GetCount() == 1){
			cirve.RemoveAll();
			IsDelete = false;
			KillTimer(0);
			return;
		}
		do {
		cirve.RemoveAt(cirve.GetCount()-1);
		} while (!(cirve[cirve.GetCount()-1].getIsEnd()));
		Invalidate();
	}
	CWnd::OnTimer(nIDEvent);
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return true;
}
