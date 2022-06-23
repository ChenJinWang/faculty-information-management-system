// ChartDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "ChartDlg.h"
#include "afxdialogex.h"
#include "GPersonList.h"


// CChartDlg �Ի���

IMPLEMENT_DYNAMIC(CChartDlg, CDialogEx)

CChartDlg::CChartDlg(int arr[],CWnd* pParent /*=NULL*/)
	: CDialogEx(CChartDlg::IDD, pParent)
{
	m_iArray[0] = arr[0];
	m_iArray[1] = arr[1];
}

CChartDlg::~CChartDlg()
{
}

void CChartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChartDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CChartDlg ��Ϣ�������


void CChartDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CGPersonList::PaintChart(this->m_hWnd,m_iArray,IDC_CHART);
}
