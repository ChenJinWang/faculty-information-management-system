#pragma once


// CLoging 对话框

class CLoging : public CDialogEx
{
	DECLARE_DYNAMIC(CLoging)

public:
	CLoging(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoging();

// 对话框数据
	enum { IDD = IDD_LOGING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strZhangHao;
	CString m_strMiMa;
	afx_msg void OnPaint();
	afx_msg void OnStatic();

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
