// MyDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "finalterm_w5.h"
#include "MyDialog.h"
#include "afxdialogex.h"
#include <string>


// MyDialog ��ȭ �����Դϴ�.

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


// MyDialog �޽��� ó�����Դϴ�.


void MyDialog::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	TextBox.SetWindowText(str);
	for (int i = 0; i < 3; i++) {
		CString temp;
		temp.Format(_T("%d"), color[i]);
		ColorBox[i].SetWindowText(temp);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
