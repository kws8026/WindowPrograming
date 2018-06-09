
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "finalterm_w2.h"
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
	ON_COMMAND(ID_SAVE, &CChildView::OnSave)
	ON_COMMAND(ID_NEW, &CChildView::OnNew)
	ON_COMMAND(ID_LOAD, &CChildView::OnLoad)
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
	for (int i = 0; i < posArr.GetCount(); i++)
	{
		dc.Ellipse(posArr[i].x-20, posArr[i].y-20, posArr[i].x + 20, posArr[i].y + 20);
	}
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}



void CChildView::OnSave()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CFile file;
	CFileException e;
	if (!(file.Open(_T("circle.dat"), CFile::modeWrite | CFile::modeCreate), &e)){
		e.ReportError();
		return;
	}
	CArchive ar(&file, CArchive::store);
	posArr.Serialize(ar);
	Invalidate();
}


void CChildView::OnNew()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	posArr.RemoveAll();
	Invalidate();
}


void CChildView::OnLoad()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CFile file;
	CFileException e;
	if (!(file.Open(_T("circle.dat"), CFile::modeRead), &e)) {
		e.ReportError();
		return;
	}
	CArchive ar(&file, CArchive::load);
	posArr.RemoveAll();
	posArr.Serialize(ar);
	Invalidate();
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	posArr.Add(point);
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}
