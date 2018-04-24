
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "Midterm_w7.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_Pos = { 0,0 };
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
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

	dc.Rectangle(m_Pos.x, m_Pos.y, m_Pos.x + 100, m_Pos.y + 100);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (nChar)
	{
	case VK_UP:
		m_Pos.y -= 10;
		break;
	case VK_DOWN:
		m_Pos.y += 10;
		break;
	case VK_LEFT:
		m_Pos.x -= 10;
		break;
	case VK_RIGHT:
		m_Pos.x += 10;
		break;
	default:
		return;
	}
	CRect rect;
	GetClientRect(rect);
	if (m_Pos.x < 0) { m_Pos.x += 15; }
	if (m_Pos.y < 0) { m_Pos.y += 15; }
	if (m_Pos.x + 100 > rect.Width()) { m_Pos.x -= 15; }
	if (m_Pos.y + 100 > rect.Height()) { m_Pos.y -= 15; }

	Invalidate();
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (point.x > m_Pos.x + 100)	m_Pos.x += 10;
	else if (point.x < m_Pos.x)		m_Pos.x -= 10;
	if (point.y > m_Pos.y + 100)	m_Pos.y += 10;
	else if (point.y < m_Pos.y)		m_Pos.y -= 10;

	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}
