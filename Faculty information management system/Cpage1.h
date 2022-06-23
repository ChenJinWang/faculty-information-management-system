#pragma once


// Cpage1 对话框

class Cpage1 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage1)

public:
	Cpage1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage1();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
