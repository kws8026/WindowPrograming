
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "HW_w4.h"
#include "ChildView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView() : played(false), Count(0)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(131, Clear)
	ON_BN_CLICKED(132, Save)
	ON_BN_CLICKED(133, Load)
	ON_BN_CLICKED(134, Play)
	ON_BN_CLICKED(135, EndPlay)

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
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
	CDC memDC;
	CRect rect;
	GetClientRect(rect);
	memDC.CreateCompatibleDC(&dc);
	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memDC.SelectObject(bitmap);
	memDC.FillRect(rect,WHITE_BRUSH);
	// 선그리기
	if(!(arrPawn.IsEmpty()))memDC.MoveTo(arrPawn[0].getPos());
	for (int i = 1; i < arrPawn.GetCount(); i++) {
		CPen pen;
		if (played) {
			pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
			memDC.SelectObject(&pen);
		}
		memDC.LineTo(arrPawn[i].getPos());
	}
	// 사각형 및 원 그리기
	if (played){
		memDC.Rectangle(pos.x - 20, pos.y - 20, pos.x + 20, pos.y + 20);
	}
	else {
		for (int i = 0; i < arrPawn.GetCount(); i++) {
			CPen pen(PS_SOLID, 1, RGB(0,0,0));
			if (i == Count) {
				pen.DeleteObject();
				pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
			}
			memDC.SelectObject(&pen);
			arrPawn[i].Draw(memDC);
		}
	}
	dc.BitBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	CString str[5];
	str[0] = _T("CLEAR");
	str[1] = _T("SAVE");
	str[2] = _T("LOAD");
	str[3] = _T(">");
	str[4] = _T("||");
	for (int i = 0; i < 5; i++){
		button[i].Create(str[i], BS_PUSHBUTTON | WS_VISIBLE, CRect(i * 50, 0, (i * 50) + 50, 30), this, 131 + i);
	}
	scroll.Create(SBS_HORZ | WS_VISIBLE, CRect(250, 0, 800, 30), this, 136);
	SetTimer(0, 300, NULL);
	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	
	return 0;
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (played || point.y < 30) return;
	arrPawn.Add(point);
	Invalidate();
	int num = arrPawn.GetCount() - 1;
	scroll.SetScrollRange(0, num);
	scroll.SetScrollPos(num);
	Count = num;
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 0 && played == true)
	{
	}
	CWnd::OnTimer(nIDEvent);
}


void CChildView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nSBCode != NULL)
	{
		switch (nSBCode)
		{
			case SB_THUMBPOSITION:
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				Count = nPos;
				Invalidate();
				break;
			case SB_LINERIGHT:
				if (Count < arrPawn.GetCount()-1)
					pScrollBar->SetScrollPos(++Count);
				Invalidate();
				break;
			case SB_LINELEFT:
				if (Count > 0)
					pScrollBar->SetScrollPos(--Count);
				Invalidate();
				break;
		default:
			break;
		}
		
	}
	CWnd::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CChildView::Clear()
{
	arrPawn.RemoveAll();
	Invalidate();
	AfxMessageBox(_T("정리되었습니다."));
}

void CChildView::Save()
{
	CFile file;
	CFileException e;
	if (!file.Open(_T("SaveData.dat"), CFile::modeReadWrite | CFile::modeCreate, &e))
		e.ReportError();
	CArchive ar(&file, CArchive::store);
	arrPawn.Serialize(ar);
	AfxMessageBox(_T("저장되었습니다."));
}

void CChildView::Load()
{
	CFile file;
	CFileException e;
	if (!file.Open(_T("SaveData.dat"), CFile::modeRead, &e))
		e.ReportError();
	CArchive ar(&file, CArchive::load);
	arrPawn.Serialize(ar);

	int num = arrPawn.GetCount() - 1;
	scroll.SetScrollRange(0, num);
	scroll.SetScrollPos(num);
	Count = num;

	Invalidate();
	AfxMessageBox(_T("불러왔습니다."));
}

void CChildView::Play()
{
	played = true;
	Count = 0;
	Invalidate();
}

void CChildView::EndPlay()
{
	played = false;
	Count = arrPawn.GetCount() - 1;
	Invalidate();
}
