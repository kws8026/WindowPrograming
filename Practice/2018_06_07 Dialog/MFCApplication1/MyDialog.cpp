// MyDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog ��ȭ �����Դϴ�.

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


// MyDialog �޽��� ó�����Դϴ�.


void MyDialog::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialog::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

static COLORREF Pallet[3] = { RGB(255,0,0),RGB(0,255,0),RGB(0,0,255) };

void MyDialog::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	for (int i = 0; i < 3; i++)
		if (Radio[i].GetCheck())
			color = Pallet[i];

	CDialog::OnOK();
}


BOOL MyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	for (int i = 0; i < 3; i++)
		if (color == Pallet[i])
			Radio[i].SetCheck(true);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
