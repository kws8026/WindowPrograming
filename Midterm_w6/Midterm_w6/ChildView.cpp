
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Midterm_w6.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_Point = { 0,0 }; m_Radian = 50; m_v = 10; m_Color = 50; m_vc = 5;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
ON_WM_MOUSEMOVE()
ON_WM_TIMER()
ON_WM_CREATE()
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
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(rect);
	CDC memDC;
	CBitmap bitmap;
	memDC.CreateCompatibleDC(&dc);
	bitmap.CreateCompatibleBitmap(&memDC, rect.Width(), rect.Height());
	CBrush brush(RGB(m_Color, m_Color, m_Color));
	memDC.SelectObject(&brush);
	memDC.SelectObject(&bitmap);

	memDC.Ellipse(m_Point.x - m_Radian, m_Point.y - m_Radian, m_Point.x + m_Radian, m_Point.y + m_Radian);

	dc.BitBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_Point = point;
	Invalidate();
	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 0)
	{
		if (m_Radian < 20 || m_Radian > 100) m_v = -m_v;
		m_Radian += m_v;
		Invalidate();
	}
	if (nIDEvent == 1)
	{
		if (m_Color > 200 || m_Color < 10) m_vc = -m_vc;
		m_Color += m_vc;
		Invalidate();
	}
	CWnd::OnTimer(nIDEvent);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(0, 50, NULL);
	SetTimer(1, 1000, NULL);
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return true;
}
