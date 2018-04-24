
// ChildView.cpp : CChildView Ŭ������ ����
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



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
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

	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
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
    // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
    if (CWnd::OnCreate(lpCreateStruct) == -1)
        return -1;

    // TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
    //CBitmap bitmap;
    //BITMAP bmpinfo;
    //bitmap.LoadBitmap(IDB_BITMAP1);
    //bitmap.GetBitmap(&bmpinfo);
    //RECT m_Rect = { 0, 0, bmpinfo.bmWidth ,bmpinfo.bmHeight};     // �����ϰ� ���� ����� RECT ������ �ʱ�ȭ. ���⼭�� 1024x768�� �����Ͽ���.

    //AdjustWindowRect(&m_Rect, WS_OVERLAPPEDWINDOW, FALSE);

    //int width = m_Rect.right - m_Rect.left;

    //int height = m_Rect.bottom - m_Rect.top;

    //this->SetWindowPos(NULL, 0, 0, width, height, 0);


    return 0;
}
