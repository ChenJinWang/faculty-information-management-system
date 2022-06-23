#pragma once
#include "afxcmn.h"
#include "Cpage1.h"
#include "Cpage2.h"
#include "Cpage3.h"


// CmfcxxklDlg 对话框

class CmfcxxklDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CmfcxxklDlg)

public:
	CmfcxxklDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CmfcxxklDlg();
	Cpage1 page1;
	Cpage2 page2;
	Cpage3 page3;
// 对话框数据
	enum { IDD = IDD_TAB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HICON m_hIcon;
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
