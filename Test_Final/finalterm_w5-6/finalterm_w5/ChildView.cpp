
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "finalterm_w5.h"
#include "ChildView.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView(): color(RGB(0,0,0))
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
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
	int tap = 0;
	for (int i = 0; i < str.GetLength(); i++)
		if (str[i] == '\n')
			tap += 8;
	CRect temp(0, (rect.Height() / 2) - 8- tap, rect.Width(), (rect.Height() / 2) + 8+ tap);
	dc.SetTextColor(color);
	dc.DrawText(str, temp, DT_CENTER);
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	MyDialog dlg;
	dlg.str = str;
	dlg.MecroColor(color);
	dlg.DoModal();
	str = dlg.str;
	color = RGB(dlg.color[0], dlg.color[1], dlg.color[2]);
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}
