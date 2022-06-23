#pragma once


// Cpage3 对话框

class Cpage3 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage3)

public:
	Cpage3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage3();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
