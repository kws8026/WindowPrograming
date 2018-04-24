
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "HW_w2.h"
#include "ChildView.h"
#include "MyCircle.h"
#include "MyRect.h"
#include "MyPolygon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	RBClicked = false; LBClicked = false; DrawPolgon = false; pMpos = NULL;
}

CChildView::~CChildView()
{
	for (int i = 0; i < ArrShape.GetCount(); i++)
	{
		delete ArrShape[i];
	}
	ArrShape.RemoveAll();
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MBUTTONDOWN()
	ON_WM_ERASEBKGND()
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
	CRect rect;
	GetClientRect(rect);
	CBitmap bitmap;
	CBrush brush(RGB(180,180,180));
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memDC.SelectObject(&bitmap);
	memDC.FillRect(rect,&brush);

	for (int i = 0; i < ArrShape.GetCount(); i++)
	{
		ArrShape[i]->draw(memDC);
	}

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!LBClicked && !RBClicked) return;
	ArrShape[ArrShape.GetCount() -1]->SetPoint(pMpos, point);
	Invalidate(false);
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (RBClicked || DrawPolgon) return;
	ArrShape.Add(new CMyRect());
	GetCapture();
	pMpos = point;
	LBClicked = true;
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!LBClicked) return;

	ReleaseCapture();
	Invalidate();
	LBClicked = false;

	CWnd::OnLButtonUp(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (LBClicked || DrawPolgon) return;
	ArrShape.Add(new CMyCircle());
	GetCapture();
	pMpos = point;
	RBClicked = true;
	CWnd::OnRButtonDown(nFlags, point);
}


void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (!RBClicked) return;
	ReleaseCapture();
	Invalidate();
	RBClicked = false;

	CWnd::OnRButtonUp(nFlags, point);
}


void CChildView::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (RBClicked || LBClicked) return;
	if (!DrawPolgon)
	{
		DrawPolgon = true;
		ArrShape.Add(new CMyPolygon());
	}
	ArrShape[ArrShape.GetCount() - 1]->AddPoint(point);
	CClientDC dc(this);
	dc.Ellipse(point.x - 3, point.y - 3, point.x + 3, point.y + 3);
	CWnd::OnMButtonDown(nFlags, point);
}

void CChildView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (LBClicked || RBClicked) return;
	Invalidate();
	DrawPolgon = false;
	CWnd::OnLButtonDblClk(nFlags, point);
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return true;
}
