
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ChildView.h"
#include "MyDialog.h"
#include "MyDialogEx.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView() :dlgEx(NULL)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
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
	CRect rect(100, 100, 300, 300);
	dc.Rectangle(rect);
	rect.DeflateRect(2, 2);
	if (color != RGB(0, 0, 0))
		dc.SetTextColor(color);
	dc.DrawText(str, rect, DT_LEFT);
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (dlgEx != NULL)
		return;
	MyDialog dlg;
	dlg.str = str;
	dlg.color = color;
	dlg.DoModal();
	
	str = dlg.str;
	color = dlg.color;
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (dlgEx != NULL)
		dlgEx->SetFocus();
	else {
		dlgEx = new MyDialogEx();
		dlgEx->pView = this;
		dlgEx->str = str;
		dlgEx->color = color;
		dlgEx->Create(IDD_DIALOG2);
		dlgEx->ShowWindow(SW_SHOWDEFAULT);
	}

	CWnd::OnRButtonDown(nFlags, point);
}
