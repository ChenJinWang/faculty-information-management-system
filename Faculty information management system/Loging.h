#pragma once


// CLoging �Ի���

class CLoging : public CDialogEx
{
	DECLARE_DYNAMIC(CLoging)

public:
	CLoging(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoging();

// �Ի�������
	enum { IDD = IDD_LOGING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strZhangHao;
	CString m_strMiMa;
	afx_msg void OnPaint();
	afx_msg void OnStatic();

	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
