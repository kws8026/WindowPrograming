
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "MFCApplication4.h"
#include "ChildView.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
    x= 0; y = 0; pro = 1;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
    ON_WM_SIZE()
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
	CDC memDC;
    memDC.CreateCompatibleDC(&dc);
    CBitmap bitmap;
    BITMAP bmpinfo;
    bitmap.LoadBitmap(IDB_BITMAP1);
    bitmap.GetBitmap(&bmpinfo);
    memDC.SelectObject(&bitmap);
    CRect rect;
    GetClientRect(rect);
    pro = (float)bmpinfo.bmWidth / (float)bmpinfo.bmHeight;
    dc.StretchBlt((rect.Width() - x) / 2,(rect.Height() - y) / 2, x , y ,&memDC, 0,0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnSize(UINT nType, int cx, int cy)
{
    CWnd::OnSize(nType, cx, cy);
    if(!cx&&!cy) return;
    float f = (float)cx / (float)cy;
    if (f < pro)
    {
        x = cx;
        y = x / pro;
    }
    else
    {
        y = cy;
        x = y * pro;
  
    }
    // TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  여기에 특수화된 작성 코드를 추가합니다.
    //CBitmap bitmap;
    //BITMAP bmpinfo;
    //bitmap.LoadBitmap(IDB_BITMAP1);
    //bitmap.GetBitmap(&bmpinfo);
    //RECT m_Rect = { 0, 0, bmpinfo.bmWidth ,bmpinfo.bmHeight};     // 생성하고 싶은 사이즈를 RECT 변수에 초기화. 여기서는 1024x768로 설정하였다.

    //AdjustWindowRect(&m_Rect, WS_OVERLAPPEDWINDOW, FALSE);

    //int width = m_Rect.right - m_Rect.left;

    //int height = m_Rect.bottom - m_Rect.top;

    //this->SetWindowPos(NULL, 0, 0, width, height, 0);


    return 0;
}
