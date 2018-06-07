// MyDialogEx.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MyDialogEx.h"
#include "afxdialogex.h"
#include "ChildView.h"


// MyDialogEx 대화 상자입니다.

IMPLEMENT_DYNAMIC(MyDialogEx, CDialogEx)

MyDialogEx::MyDialogEx(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

MyDialogEx::~MyDialogEx()
{
}

void MyDialogEx::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, str);
	DDX_Control(pDX, IDC_EDIT1, TextBox);
	DDX_Control(pDX, IDC_RADIO1, Radio[0]);
	DDX_Control(pDX, IDC_RADIO2, Radio[1]);
	DDX_Control(pDX, IDC_RADIO3, Radio[2]);
}


BEGIN_MESSAGE_MAP(MyDialogEx, CDialogEx)
	ON_BN_CLICKED(IDOK, &MyDialogEx::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MyDialogEx::OnBnClickedCancel)
END_MESSAGE_MAP()


// MyDialogEx 메시지 처리기입니다.

static COLORREF Pallet[3] = { RGB(255,0,0),RGB(0,255,0),RGB(0,0,255) };

BOOL MyDialogEx::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	for (int i = 0; i < 3; i++)
		if (color == Pallet[i])
			Radio[i].SetCheck(true);
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void MyDialogEx::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	for (int i = 0; i < 3; i++)
		if (Radio[i].GetCheck())
			color = Pallet[i];
	pView->str = str;
	pView->color = color;
	pView->Invalidate();
}


void MyDialogEx::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	pView->dlgEx = NULL;
	DestroyWindow();
}
