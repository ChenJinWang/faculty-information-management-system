#pragma once


// CSuperChartDlg �Ի���

class CSuperChartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSuperChartDlg)

public:
	CSuperChartDlg(CWnd* pParent = NULL);   // ��׼���캯��
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

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void DrawChart(int type,CString title,int interval,int max,int sum,CString XN,CString YN);
};
