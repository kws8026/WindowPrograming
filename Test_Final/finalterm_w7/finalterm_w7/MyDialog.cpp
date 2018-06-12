// MyDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "finalterm_w7.h"
#include "MyDialog.h"
#include "ChildView.h"
#include "afxdialogex.h"


// MyDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(MyDialog, CDialog)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, 1000, Number[0]);
	DDX_Control(pDX, 1001, Number[1]);
	DDX_Control(pDX, 1002, Number[2]);
	DDX_Control(pDX, 1003, Number[3]);
	DDX_Control(pDX, 1004, Number[4]);
	DDX_Control(pDX, 1005, Number[5]);
	DDX_Control(pDX, 1006, Number[6]);
	DDX_Control(pDX, 1007, Number[7]);
	DDX_Control(pDX, 1008, Number[8]);
	DDX_Control(pDX, 1009, Number[9]);
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
	ON_BN_CLICKED(IDC_PLUS, &MyDialog::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_MINUS, &MyDialog::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MLTIP, &MyDialog::OnBnClickedMltip)
	ON_BN_CLICKED(IDC_DIVIDE, &MyDialog::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_END, &MyDialog::OnBnClickedEND)
	ON_BN_CLICKED(IDC_CLEAR, &MyDialog::OnBnClickedCLEAR)
	ON_BN_CLICKED(IDC_BACKSPACE, &MyDialog::OnBnClickedBackspace)
	ON_COMMAND_RANGE(IDC_0,IDC_9,  &MyDialog::OnBnClickedNumber)
END_MESSAGE_MAP()


// MyDialog 메시지 처리기입니다.

void MyDialog::OnBnClickedPlus()
{
	strptr->AppendChar('+');
	viewptr->Invalidate();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MyDialog::OnBnClickedMinus()
{
	strptr->AppendChar('-');
	viewptr->Invalidate();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MyDialog::OnBnClickedMltip()
{
	strptr->AppendChar('*');
	viewptr->Invalidate();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MyDialog::OnBnClickedDivide()
{
	strptr->AppendChar('/');
	viewptr->Invalidate();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void MyDialog::OnBnClickedEND()
{
	strptr->AppendChar('=');
	char* arr;
	arr = new char[strptr->GetLength()];
	for (int i = 0; i < strptr->GetLength(); i++)
		arr[i] = strptr->GetAt(i);
	float temp = atoi(arr);
	while (*arr != '=')	{
		if (*arr < '0' || *arr > '9'){
			if (*arr == '+') temp += atoi(++arr);
			if (*arr == '-') temp -= atoi(++arr);
			if (*arr == '/') {
				if (atoi(++arr) == 0) {
					OnBnClickedCLEAR();
					return;
				}
				temp /= atoi(arr);
			}
			if (*arr == '*') temp *= atoi(++arr);
			continue;
		}
		arr++;
	}
	CString str;
	str.Format(_T("%.2f"), temp);
	strptr->Append(str);
	viewptr->Invalidate();

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MyDialog::OnBnClickedCLEAR()
{
	strptr->Empty();
	viewptr->Invalidate();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MyDialog::OnBnClickedBackspace()
{
	if (strptr->IsEmpty()) return;
	strptr->ReleaseBuffer(strptr->GetLength()-1);
	viewptr->Invalidate();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void MyDialog::OnBnClickedNumber(UINT id)
{
	strptr->AppendChar('0' + id - 1000);
	viewptr->Invalidate();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
