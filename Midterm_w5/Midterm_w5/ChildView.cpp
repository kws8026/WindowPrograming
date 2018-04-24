
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Midterm_w5.h"
#include "ChildView.h"
#include "Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_Width = 1420; m_Heighst = 653;
	m_BmpX = 0; m_BmpY = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
//	ON_WM_SIZING()
ON_WM_SIZE()
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
	memDC.CreateCompatibleDC(&dc);
	CBitmap bit;
	BITMAP bmpinfo;
	bit.LoadBitmap(IDB_BITMAP1);
	bit.GetBitmap(&bmpinfo);
	memDC.SelectObject(&bit);

	if(m_BmpX > -bmpinfo.bmWidth || m_BmpY > -bmpinfo.bmHeight)
	dc.StretchBlt((rect.Width() - bmpinfo.bmWidth - m_BmpX) /2,(rect.Height() - bmpinfo.bmHeight- m_BmpY)/2,
		bmpinfo.bmWidth + m_BmpX, bmpinfo.bmHeight + m_BmpY,
		&memDC,0,0,bmpinfo.bmWidth,bmpinfo.bmHeight,SRCCOPY);

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



//void CChildView::OnSizing(UINT fwSide, LPRECT pRect)
//{
//	CWnd::OnSizing(fwSide, pRect);
//
//	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
//}


void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	if (!cx || !cy) return;
	if(cx != m_Width)
	{ 
		m_BmpX += (cx - m_Width)/2 ;
		m_BmpY = m_BmpX;
		m_Width = cx;
	}
	if(cy != m_Heighst) 
	{
		m_BmpY += (cy - m_Heighst) / 2;
		m_BmpX = m_BmpY;
		m_Heighst = cy;
	}
	Invalidate();
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
