
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "HW_w3.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define BrushSize 5
// CChildView

CChildView::CChildView() : Eraser(false), m_Vx(0), m_Vy(0), m_color(RGB(0, 0, 0)), m_brush(Rect), Animation(false)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(131, OnBSRectangle)
	ON_COMMAND(132, OnBSCircle)
	ON_COMMAND(133, OnAnimation)
	ON_COMMAND(201, OnBlack)
	ON_COMMAND(202, OnRed)
	ON_COMMAND(203, OnGreen)
	ON_COMMAND(204, OnBlue)
	ON_UPDATE_COMMAND_UI(131, OnUpdateRectangle)
	ON_UPDATE_COMMAND_UI(132, OnUpdateCircle)
	ON_UPDATE_COMMAND_UI(133, OnUpdateAnimation)
	ON_UPDATE_COMMAND_UI(201, OnUpdateBlack)
	ON_UPDATE_COMMAND_UI(202, OnUpdateRed)
	ON_UPDATE_COMMAND_UI(203, OnUpdateGreen)
	ON_UPDATE_COMMAND_UI(204, OnUpdateBlue)
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
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc,rect.Width(),rect.Height());
	memDC.SelectObject(&bitmap);
	memDC.FillSolidRect(rect, RGB(255, 255, 255));

	POSITION pos = ShapeList.GetHeadPosition();
	while (pos != NULL)
	{
		ShapeList.GetAt(pos).Draw(memDC);
		ShapeList.GetNext(pos);
	}
	if (Eraser)
	{
		CPen pen;
		CBrush brush(0xFFFFFF);
		pen.CreatePen(PS_SOLID, 5, 0xB54461);
		memDC.SelectObject(&pen);
		memDC.SelectObject(&brush);
		memDC.Rectangle(m_point.x,m_point.y, m_point.x + EraserSize[0], m_point.y + EraserSize[1]);
		brush.DeleteObject();
	}
	CString str;
	str.Format(_T("%d"), ShapeList.GetCount());
	CFont font;
	font.CreatePointFont(200, _T("Arial Black"));
	memDC.SelectObject(&font);
	memDC.TextOut(5, 5, str);
	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, SRCCOPY);
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}

void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nFlags == MK_LBUTTON)
	{
		if(Eraser) Eraser = false;
		if (Animation) Animation = false;
		CShape shape(BrushSize,m_brush,point,m_color);
		ShapeList.AddTail(shape);
		Invalidate();
	}
	if (nFlags == MK_RBUTTON)
	{
		EraserSize[0] = point.x - m_point.x;
		EraserSize[1] = point.y - m_point.y;
		Invalidate();
	}
	CWnd::OnMouseMove(nFlags, point);
}

void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_point = point;
	Eraser = true;
	EraserSize[0] = 0;
	EraserSize[1] = 0;
	Invalidate();
	CWnd::OnRButtonDown(nFlags, point);
}

void CChildView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	int temp;
	if (m_point.x > point.x) 
	{
		temp = point.x;
		point.x = m_point.x;
		m_point.x = temp;
	}
	if (m_point.y > point.y)
	{
		temp = point.y;
		point.y = m_point.y;
		m_point.y = temp;
	}

	EraserSize[0] = point.x - m_point.x;
	EraserSize[1] = point.y - m_point.y;

	CRect rect(m_point.x + BrushSize, m_point.y + BrushSize, point.x - BrushSize, point.y - BrushSize);
	POSITION pos = ShapeList.GetHeadPosition();
	while (pos != NULL)
	{
		POSITION oldpos = pos;
		if (rect.PtInRect(ShapeList.GetNext(pos).GetPos()) && !ShapeList.IsEmpty())
		{
			ShapeList.RemoveAt(oldpos);
		}
	}
	Invalidate();

	CWnd::OnRButtonUp(nFlags, point);
}

void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == 0 && Animation == true)
	{
		CRect rect;
		GetClientRect(rect);
		if (m_point.x < 0 || m_point.x > rect.Width() - EraserSize[0]) m_Vx *= -1;
		if (m_point.y < 0 || m_point.y > rect.bottom - EraserSize[1]) m_Vy *= -1;
		m_point.x += m_Vx;
		m_point.y += m_Vy;
		POSITION pos = ShapeList.GetHeadPosition();
		CRect Erect{ m_point.x + BrushSize,m_point.y + BrushSize,m_point.x + EraserSize[0] - BrushSize,m_point.y + EraserSize[1] - BrushSize };
		while (pos != NULL)
		{
			POSITION oldpos = pos;
			if (Erect.PtInRect(ShapeList.GetNext(pos).GetPos()) && !ShapeList.IsEmpty())
			{
				ShapeList.RemoveAt(oldpos);
			}
		}
		Invalidate();
	}
	CWnd::OnTimer(nIDEvent);
}

void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (nChar)
	{
	case VK_DOWN:
		m_Vy = 10;
		m_Vx = 0;
		break;
	case VK_UP:
		m_Vy = -10;
		m_Vx = 0;
		break;
	case VK_RIGHT:
		m_Vy = 0;
		m_Vx = 10;
		break;
	case VK_LEFT:
		m_Vy = 0;
		m_Vx = -10;
		break;
	case 'R':
		OnRed();
		break;
	case 'G':
		OnGreen();
		break;
	case 'B':
		OnBlue();
		break;
	default:
		break;
	}
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(0, 100, NULL);
	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}

BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return true;
}

void CChildView::OnUpdateAnimation(CCmdUI * pCmdUI)
{
	pCmdUI->SetCheck(Animation == true);
}

void CChildView::OnUpdateRectangle(CCmdUI * pCmdUI)
{
	pCmdUI->SetCheck(m_brush == Rect);
}

void CChildView::OnUpdateCircle(CCmdUI * pCmdUI)
{
	pCmdUI->SetCheck(m_brush == Circle);
}

void CChildView::OnUpdateBlack(CCmdUI * pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(0,0,0));
}

void CChildView::OnUpdateRed(CCmdUI * pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(255, 0, 0));

}

void CChildView::OnUpdateGreen(CCmdUI * pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(0, 255, 0));
}

void CChildView::OnUpdateBlue(CCmdUI * pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(0, 0, 255));
}
