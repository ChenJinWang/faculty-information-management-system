// Clogin.cpp : 实现文件
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "Clogin.h"
#include "afxdialogex.h"


// Clogin 对话框

IMPLEMENT_DYNAMIC(Clogin, CDialogEx)

Clogin::Clogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(Clogin::IDD, pParent)
{

}

Clogin::~Clogin()
{
}

void Clogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Clogin, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Clogin 消息处理程序


void Clogin::OnPaint()
{
	
}
