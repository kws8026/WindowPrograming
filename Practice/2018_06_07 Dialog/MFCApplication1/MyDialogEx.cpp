// MyDialogEx.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MyDialogEx.h"
#include "afxdialogex.h"
#include "ChildView.h"


// MyDialogEx ��ȭ �����Դϴ�.

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


// MyDialogEx �޽��� ó�����Դϴ�.

static COLORREF Pallet[3] = { RGB(255,0,0),RGB(0,255,0),RGB(0,0,255) };

BOOL MyDialogEx::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	for (int i = 0; i < 3; i++)
		if (color == Pallet[i])
			Radio[i].SetCheck(true);
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void MyDialogEx::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	pView->dlgEx = NULL;
	DestroyWindow();
}
