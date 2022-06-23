// Cpage1.cpp : 实现文件
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "Cpage1.h"
#include "afxdialogex.h"
#include "CmfcxxklDlg.h"



// Cpage1 对话框

IMPLEMENT_DYNAMIC(Cpage1, CDialogEx)

Cpage1::Cpage1(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cpage1::IDD, pParent)
{

}

Cpage1::~Cpage1()
{
}

void Cpage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpage1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Cpage1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cpage1::OnBnClickedButton2)
END_MESSAGE_MAP()


// Cpage1 消息处理程序


void Cpage1::OnBnClickedButton1()
{
	CString tmp;
	GetDlgItem(IDC_EDIT1)->GetWindowText(tmp);

	((CmfcxxklDlg*)AfxGetMainWnd())->page2.GetDlgItem(IDC_RESULT)->SetWindowText(tmp); 

	//GetDlgItem(IDC_RESULT)->SetWindowText(tmp);
	//MessageBox(tmp)
}


void Cpage1::OnBnClickedButton2()
{
	CString tmp;
	GetDlgItem(IDC_EDIT2)->GetWindowText(tmp);
	AfxGetMainWnd()->GetDlgItem(IDC_TEST)->SetWindowText(tmp);
}

