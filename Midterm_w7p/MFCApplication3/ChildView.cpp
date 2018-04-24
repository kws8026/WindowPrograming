
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
    m_v  = 0 ; m_a = 10; CountDown = 0;
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
    CRect rect;
    GetClientRect(rect);
    int Num = m_pos.GetCount() + 1;
    for (int i = 0; i < m_pos.GetCount(); i++)
    {
        m_pos[i].x = rect.Width() / Num * (i+1);
        dc.Ellipse(m_pos[i].x, m_pos[i].y, m_pos[i].x+ 50, m_pos[i].y +50);
    }
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    if(nChar == VK_SPACE)
    {
       CCircle cir(0, 0);
       m_pos.Add(cir);
       for(int i = 0; i < m_pos.GetCount(); i++) 
       {
          m_pos[i].y = 0;
          m_pos[i].v = 0;
          m_pos[i].b = false;
       }
       CountDown = 0;
       Invalidate();
    }
    CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
    // TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
    if(nIDEvent == 0)
    {
        CRect rect;
        GetClientRect(rect);
        float m_f = 0.33f;
        for (int i = 0; i < m_pos.GetCount(); i++)
        { 
            if(!m_pos[i].b) break;
            m_pos[i].v += m_a * m_f;
            m_pos[i].y += m_pos[i].v * m_f;
            if(m_pos[i].y >= rect.bottom - 50)
            {
                m_pos[i].y = rect.bottom - 50;
                m_pos[i].v *= -0.8;
            }
        }
        Invalidate();
    }
    if (nIDEvent == 1)
    {
        if (!m_pos.GetCount() || m_pos.GetCount() - 1 < CountDown) return;
        m_pos[CountDown].b = true;
        CountDown++;
    }   
    CWnd::OnTimer(nIDEvent);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;
        SetTimer(0,33,NULL);
        SetTimer(1, 100, NULL);
    // TODO:  여기에 특수화된 작성 코드를 추가합니다.

    return 0;
}
