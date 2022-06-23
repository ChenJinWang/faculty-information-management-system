// SuperChartDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "SuperChartDlg.h"
#include "afxdialogex.h"

#include "Graph.h"
#include "GraphSeries.h"
// CSuperChartDlg �Ի���

IMPLEMENT_DYNAMIC(CSuperChartDlg, CDialogEx)

CSuperChartDlg::CSuperChartDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSuperChartDlg::IDD, pParent)
{

}

CSuperChartDlg::CSuperChartDlg(int arr[],int type,CString title,int interval,int max,int sum,CString XN,CString YN,CWnd* pParent /*=NULL*/)
	: CDialogEx(CSuperChartDlg::IDD, pParent),m_type(type),m_title(title),
	m_interval(interval),m_max(max),m_sum(sum),m_XN(XN),m_YN(YN)
{
	m_iArr[0] = arr[0];
	m_iArr[1] = arr[1];
}

CSuperChartDlg::~CSuperChartDlg()
{
}

void CSuperChartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSuperChartDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSuperChartDlg ��Ϣ�������


void CSuperChartDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	DrawChart(m_type,m_title,m_interval,m_max,m_sum,m_XN,m_YN);
}


void CSuperChartDlg::DrawChart(int type,CString title,int interval,int max,int sum,CString XN,CString YN)
{
	CGraph* MyGraph = new CGraph(type);
	MyGraph->SetGraphTitle(title);
	MyGraph->SetTickSpace(interval);
	MyGraph->SetTickRange(max);

	MyGraph->SetXAxisAlignment(3);
	MyGraph->SetXAxisLabel(XN);//�����ⲿ����
	MyGraph->SetYAxisLabel(YN);//�������ⲿ����

	//CString strArr[] = {L"����һ", L"���ڶ�",L"������"};
	//CString strItem[] = {L"��  ",L"Ů  ",L"ѧ��  "};

	CString strArr[] = {L"������Ů���ı���"};
	CString strItem[] = {L"��  ",L"Ů  "};



	CGraphSeries* series = new CGraphSeries();
	series->SetLabel(strArr[0]);
	
		
	series->SetData(0, m_iArr[0]);
	series->SetData(1, m_iArr[1]);
		

	MyGraph->AddSeries(series);
	MyGraph->SetLegend(0, strItem[0]);
	MyGraph->SetLegend(1, strItem[1]);
	

	
	
	//set up legend
		
	Invalidate(TRUE);
	CPaintDC dc(this); 
	MyGraph->DrawGraph(&dc);
	delete MyGraph;
}
