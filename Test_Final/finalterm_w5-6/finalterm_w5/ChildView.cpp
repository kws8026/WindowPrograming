
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "finalterm_w5.h"
#include "ChildView.h"
#include "MyDialog.h"
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
	ON_WM_LBUTTONDOWN()
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
	CRect rect;
	GetClientRect(rect);
	int tap = 0;
	for (int i = 0; i < str.GetLength(); i++)
		if (str[i] == '\n')
			tap += 8;
	CRect temp(0, (rect.Height() / 2) - 8- tap, rect.Width(), (rect.Height() / 2) + 8+ tap);
	dc.DrawText(str, temp, DT_CENTER);
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	MyDialog dlg;
	dlg.str = str;
	dlg.DoModal();
	str = dlg.str;
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}
