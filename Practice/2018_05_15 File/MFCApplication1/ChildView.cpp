
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView() : m_Color(RGB(240,100,100))
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_SAVE,Save)
	ON_COMMAND(ID_LOAD,Load)
	ON_WM_KEYDOWN()
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
	for (int i = 0; i < ArrPoint.GetCount(); i++)
	{
		CBrush brush(ArrColor[i]);
		dc.SelectObject(&brush);
		dc.Ellipse(ArrPoint[i].x - 25, ArrPoint[i].y - 25, ArrPoint[i].x + 25, ArrPoint[i].y + 25);
	}
	CString str;
	switch (m_Color)
	{
	case RGB(255,0,0):
		str.Format(_T("���� �� : ����"));
		break;
	case RGB(0, 255, 0):
		str.Format(_T("���� �� : �ʷ�"));
		break;
	case RGB(0, 0, 255):
		str.Format(_T("���� �� : �Ķ�"));
		break;
	case RGB(240, 100,100):
		str.Format(_T("���� �� : �⺻"));
		break;
	default:
		break;
	}
	str.AppendFormat(_T(", ���� ���� : %d"), ArrPoint.GetCount() );
	dc.TextOut(10, 10, str);
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}

int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	
	return 0;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	ArrPoint.Add(point);
	ArrColor.Add(m_Color);
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}

void CChildView::Save()
{
	CFile file;
	CFileException e;
	if (!file.Open(_T("Circle.dat"), CFile::modeReadWrite | CFile::modeCreate, &e))
		e.ReportError();
	CArchive ar(&file, CArchive::store);

	int num = ArrPoint.GetCount();
	ar << num;
	for(int i = 0; i < num; i++)
	{
		ar << ArrPoint[i];
	}

	/*
	ArrPoint.Serialize(ar);
	ArrColor.Serialize(ar);
	*/
	AfxMessageBox(_T("����Ǿ����ϴ�."));
}

void CChildView::Load()
{
	CFile file;
	CFileException e;
	if (!file.Open(_T("Circle.dat"), CFile::modeRead, &e))
		e.ReportError();
	CArchive ar(&file, CArchive::load);

	int num;
	ar >> num;
	ArrPoint.RemoveAll();
	for(int i = 0; i < num; i++)
	{
		CPoint temp;
		ar >> temp;
		ArrPoint.Add(temp);
	}
	/*
	ArrPoint.Serialize(ar);
	ArrColor.Serialize(ar);
	*/
	Invalidate();
	AfxMessageBox(_T("�ҷ��Խ��ϴ�."));
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (nChar)
	{
	case 'R':
		m_Color = RGB(255, 0, 0);
		break;
	case 'G':
		m_Color = RGB(0, 255, 0);
		break;
	case 'B':
		m_Color = RGB(0, 0, 255);
		break;
	case 'D':
		m_Color = RGB(240, 100, 100);
		break;
	default:
		break;
	}
	Invalidate();
	CWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}
