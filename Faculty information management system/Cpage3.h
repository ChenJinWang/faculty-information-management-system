#pragma once


// Cpage3 �Ի���

class Cpage3 : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage3)

public:
	Cpage3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage3();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
