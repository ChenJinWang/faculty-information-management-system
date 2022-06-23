#pragma once
#include "afxwin.h"
#include "CGTeacher.h"

// CGEditDlg 对话框

class CGEditDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGEditDlg)

public:
	CGEditDlg(CCGTeacher psn,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGEditDlg();

// 对话框数据
	enum { IDD = IDD_EDIT };
public:
	CCGTeacher&  GetCGTeacher()         {return m_psnGEdit;}

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
protected:
	CCGTeacher m_psnGEdit;
	CString m_strHead;

public:
	int m_bMale;
	int m_iGroup;
	CComboBox m_cbGroup;
	CString m_strJobNo;
	CString m_strJobTitle;
	CString m_strName;
	CString m_strPhoneNo;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnBrowse();
	afx_msg void OnPaint();
};
