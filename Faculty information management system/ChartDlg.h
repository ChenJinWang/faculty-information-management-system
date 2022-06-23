#pragma once


// CChartDlg 对话框

class CChartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChartDlg)

public:
	CChartDlg(int arr[],CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CChartDlg();
	int m_iArray[2];

// 对话框数据
	enum { IDD = IIDD_CHART_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
