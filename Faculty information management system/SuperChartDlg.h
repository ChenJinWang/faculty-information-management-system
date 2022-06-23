#pragma once


// CSuperChartDlg 对话框

class CSuperChartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSuperChartDlg)

public:
	CSuperChartDlg(CWnd* pParent = NULL);   // 标准构造函数
	CSuperChartDlg(int arr[],int type,CString title,int interval,int max,int sum,CString XN,CString YN,CWnd* pParent = NULL);
	virtual ~CSuperChartDlg();

	int m_type;
	CString m_title;
	int m_interval;
	int m_max;
	int m_sum;
	CString m_XN;
	CString m_YN;
	int m_iArr[2];

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void DrawChart(int type,CString title,int interval,int max,int sum,CString XN,CString YN);
};
