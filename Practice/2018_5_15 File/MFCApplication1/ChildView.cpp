
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "MFCApplication1.h"
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
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_SAVE,Save)
	ON_COMMAND(ID_LOAD,Load)
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
		dc.Ellipse(ArrPoint[i].x - 25, ArrPoint[i].y - 25, ArrPoint[i].x + 25, ArrPoint[i].y + 25);
	}
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
	ArrPoint.Serialize(ar);
}

void CChildView::Load()
{
	CFile file;
	CFileException e;
	if (!file.Open(_T("Circle.dat"), CFile::modeRead, &e))
		e.ReportError();

	CArchive ar(&file, CArchive::load);
	ArrPoint.Serialize(ar);
	Invalidate();
}