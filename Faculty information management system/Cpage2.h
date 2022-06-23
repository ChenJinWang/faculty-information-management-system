#pragma once


// Cpage2 对话框

class Cpage2 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage2)

public:
	Cpage2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage2();

// 对话框数据
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
