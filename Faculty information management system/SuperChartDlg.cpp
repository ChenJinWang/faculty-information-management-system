// SuperChartDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "SuperChartDlg.h"
#include "afxdialogex.h"

#include "Graph.h"
#include "GraphSeries.h"
// CSuperChartDlg 对话框

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


// CSuperChartDlg 消息处理程序


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
	MyGraph->SetXAxisLabel(XN);//可由外部传入
	MyGraph->SetYAxisLabel(YN);//可以由外部传入

	//CString strArr[] = {L"星期一", L"星期二",L"星期三"};
	//CString strItem[] = {L"男  ",L"女  ",L"学生  "};

	CString strArr[] = {L"男生和女生的比例"};
	CString strItem[] = {L"男  ",L"女  "};



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
