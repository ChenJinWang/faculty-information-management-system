#pragma once


// Cpage2 �Ի���

class Cpage2 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage2)

public:
	Cpage2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage2();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
