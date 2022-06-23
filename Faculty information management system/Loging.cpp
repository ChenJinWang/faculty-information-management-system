// Loging.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "Loging.h"
#include "afxdialogex.h"


// CLoging �Ի���

IMPLEMENT_DYNAMIC(CLoging, CDialogEx)

CLoging::CLoging(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoging::IDD, pParent)
	, m_strZhangHao(_T(""))
	, m_strMiMa(_T(""))
{

}

CLoging::~CLoging()
{
}

void CLoging::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ED_zhanghao, m_strZhangHao);
	DDX_Text(pDX, IDC_ED_mima, m_strMiMa);
}


BEGIN_MESSAGE_MAP(CLoging, CDialogEx)
	ON_WM_PAINT()
	ON_COMMAND(IDC_STATIC, &CLoging::OnStatic)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CLoging ��Ϣ�������


void CLoging::OnPaint()
{
	CPaintDC dc(this);				
	CBitmap bitmap;				
	bitmap.LoadBitmapW(IDB_BITMAP4);				//bitmap����Դid
	CBrush brush;				
	brush.CreatePatternBrush(&bitmap);				
	CBrush* pOldBrush =dc.SelectObject(&brush);				
	CRect rect;				
	GetClientRect(&rect);				
	dc.Rectangle(&rect);				
	dc.SelectObject(pOldBrush);				

}


void CLoging::OnStatic()
{
	// TODO: �ڴ���������������
}


HBRUSH CLoging::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	 if (nCtlColor == CTLCOLOR_STATIC)  
    {  
		CFont font;
		font.CreatePointFont(120,TEXT("���Ĳ���")); 

		if (pWnd->GetDlgCtrlID()==IDC_STA_BOY || pWnd->GetDlgCtrlID()==IDC_STA_GIRL)
		{
			pDC->SetTextColor(RGB(255, 0, 0)); 
			pDC->SetBkColor(RGB(255,250,250));
	       
		}

		if (pWnd->GetDlgCtrlID()==IDC_STATIC)
		{
			pDC->SetTextColor(RGB(255, 0, 0));  
	        pDC->SetBkMode(TRANSPARENT); 
			pDC->SelectObject(&font); //���������Լ��ֺ�
		}
	   
        
	  return (HBRUSH)::GetStockObject(NULL_BRUSH);  
	}

	return hbr;
}
