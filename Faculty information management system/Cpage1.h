#pragma once


// Cpage1 �Ի���

class Cpage1 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage1)

public:
	Cpage1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage1();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
