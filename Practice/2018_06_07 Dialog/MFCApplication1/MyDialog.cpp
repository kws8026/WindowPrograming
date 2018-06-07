// MyDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(MyDialog, CDialog)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent)
	, color(0)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, str);
	DDX_Control(pDX, IDC_EDIT1, TextBox);
	DDX_Control(pDX, IDC_RADIO1, Radio[0]);
	DDX_Control(pDX, IDC_RADIO2, Radio[1]);
	DDX_Control(pDX, IDC_RADIO3, Radio[2]);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &MyDialog::OnEnChangeEdit1)
END_MESSAGE_MAP()


// MyDialog 메시지 처리기입니다.


void MyDialog::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialog::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

static COLORREF Pallet[3] = { RGB(255,0,0),RGB(0,255,0),RGB(0,0,255) };

void MyDialog::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	for (int i = 0; i < 3; i++)
		if (Radio[i].GetCheck())
			color = Pallet[i];

	CDialog::OnOK();
}


BOOL MyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	for (int i = 0; i < 3; i++)
		if (color == Pallet[i])
			Radio[i].SetCheck(true);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
