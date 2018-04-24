
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication1.h"
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
	ON_WM_MOUSEMOVE()
//	ON_WM_ICONERASEBKGND()
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
	CDC memDC;
	CBitmap bitmap;
	memDC.CreateCompatibleDC(&dc);
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memDC.SelectObject(&bitmap);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	for(int i = m_pos.x -127 ; i < m_pos.x+ 127 ; i++)
	{
		int c = i % 256;
		for (int j = m_pos.y -127; j <  m_pos.y+127; j++)
		{
			if ((i - m_pos.x)*(i - m_pos.x) + (j - m_pos.y) * (j - m_pos.y) < 127 * 127)
				//memDC.SetPixel();
				memDC.SetPixelV(i, j, RGB(c, 0, 255 - c));
		}
	}
	dc.BitBlt(0, 0, rect.Width() , rect.Height(), &memDC, 0, 0, SRCCOPY);

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_pos = point;
	Invalidate();
	CWnd::OnMouseMove(nFlags, point);
}


//void CChildView::OnIconEraseBkgnd(CDC* pDC)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//	CWnd::OnIconEraseBkgnd(pDC);
//}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return true;
}
