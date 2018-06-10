
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "finalterm_w4.h"
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
	ON_WM_CREATE()
	ON_BN_CLICKED(130,OnClicked)
	ON_BN_CLICKED(131, OnClicked)
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
	CBitmap bitmap;
	GetClientRect(rect);
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bitmap);
	memDC.FillRect(rect, WHITE_BRUSH);

	if (Radio[0].GetCheck() == BST_CHECKED)
		memDC.Ellipse(50, 50, rect.Width() - 50, rect.Height() - 50);
	else
		memDC.Rectangle(50, 50, rect.Width() - 50, rect.Height() - 50);

	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	Radio[0].Create(_T("원"), BS_AUTORADIOBUTTON | WS_VISIBLE, CRect(0, 0, 100, 30), this, 130);
	Radio[1].Create(_T("사각형"), BS_AUTORADIOBUTTON | WS_VISIBLE, CRect(0, 30, 100, 60), this, 131);
	Radio[0].SetCheck(BST_CHECKED);
	return 0;
}

void CChildView::OnClicked()
{
	Invalidate();
}
