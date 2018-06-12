// MyDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "finalterm_w5.h"
#include "MyDialog.h"
#include "afxdialogex.h"
#include <string>


// MyDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(MyDialog, CDialog)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG1, pParent) 
{
}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, TextBox);
	DDX_Control(pDX, IDC_EDIT2, ColorBox[0]);
	DDX_Control(pDX, IDC_EDIT3, ColorBox[1]);
	DDX_Control(pDX, IDC_EDIT4, ColorBox[2]);
	DDV_MinMaxInt(pDX, color[0], 0, 255);
	DDV_MinMaxInt(pDX, color[1], 0, 255);
	DDV_MinMaxInt(pDX, color[2], 0, 255);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
END_MESSAGE_MAP()


// MyDialog 메시지 처리기입니다.


void MyDialog::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	TextBox.GetWindowText(str);
	CString temp;
	for(int i = 0; i < 3; i++){
		ColorBox[i].GetWindowText(temp);
		color[i] = StrToInt(temp.GetBuffer());
	}
	UpdateData(false);
	CDialog::OnOK();
}


BOOL MyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	TextBox.SetWindowText(str);
	for (int i = 0; i < 3; i++) {
		CString temp;
		temp.Format(_T("%d"), color[i]);
		ColorBox[i].SetWindowText(temp);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
