
// ChildView.cpp : CChildView 클래스의 구현
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
	for (int i = 0; i < posArr.GetCount(); i++)
	{
		dc.Ellipse(posArr[i].x-20, posArr[i].y-20, posArr[i].x + 20, posArr[i].y + 20);
	}
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnSave()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	posArr.RemoveAll();
	Invalidate();
}


void CChildView::OnLoad()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	posArr.Add(point);
	Invalidate();
	CWnd::OnLButtonDown(nFlags, point);
}
