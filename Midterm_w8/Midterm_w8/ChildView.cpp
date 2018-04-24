
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Midterm_w8.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_Pos = { 0,0 }; m_a = 20; m_Move = 50;
	m_ArrCircle.Add(CCircle(m_Pos, m_a));
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_WM_CREATE()
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
	for (int i = 0; i < m_ArrCircle.GetCount(); i++)
	{
		m_ArrCircle[i].Draw(dc);
	}
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar != VK_SPACE) return;
	for (int i = 0; i < m_ArrCircle.GetCount(); i++) m_ArrCircle[i].SetZero();
	CPoint point(m_Pos.x + m_Move, m_Pos.y);
	m_a -= 1;
	m_ArrCircle.Add(CCircle(point, m_a));
	m_Move += 50;
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 0)
	{
		CRect rect;
		GetClientRect(rect);
		double m_f = 0.33f;
		for(int i = 0; i < m_ArrCircle.GetCount(); i++)
		{ 
			m_ArrCircle[i].AddV( m_f * m_ArrCircle[i].GetA());
			m_ArrCircle[i].AddYpos (m_f * m_ArrCircle[i].GetV());
			if (m_ArrCircle[i].GetYpos() >= rect.bottom - 50)
			{
				m_ArrCircle[i].SetYpos(rect.bottom - 50);
				m_ArrCircle[i].SetV(-0.8 * m_ArrCircle[i].GetV());
			}
		}
		Invalidate();
	}
	CWnd::OnTimer(nIDEvent);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(0, 33, NULL);
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	return 0;
}
