#pragma once


// CChartDlg �Ի���

class CChartDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChartDlg)

public:
	CChartDlg(int arr[],CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CChartDlg();
	int m_iArray[2];

// �Ի�������
	enum { IDD = IIDD_CHART_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
