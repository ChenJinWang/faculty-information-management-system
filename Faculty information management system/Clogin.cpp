// Clogin.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "Clogin.h"
#include "afxdialogex.h"


// Clogin �Ի���

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


// Clogin ��Ϣ�������


void Clogin::OnPaint()
{
	
}
