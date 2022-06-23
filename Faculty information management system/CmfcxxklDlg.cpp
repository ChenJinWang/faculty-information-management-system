// CmfcxxklDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "CmfcxxklDlg.h"
#include "afxdialogex.h"


// CmfcxxklDlg �Ի���

IMPLEMENT_DYNAMIC(CmfcxxklDlg, CDialogEx)

CmfcxxklDlg::CmfcxxklDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmfcxxklDlg::IDD, pParent)
{

}

CmfcxxklDlg::~CmfcxxklDlg()
{
}

void CmfcxxklDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(CmfcxxklDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CmfcxxklDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CmfcxxklDlg ��Ϣ�������


BOOL CmfcxxklDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	  //��ʼ��m_tab�ؼ�
      m_tab.InsertItem(1,L"Ԥ���� ");//���ַ���ǰ�ӡ�L����ת������
      m_tab.InsertItem(2,L"��� ");//int InsertItem( int nItem,LPCTSTR lpszItem );���У�nItem�ǿؼ����е�������lpszItem�ǿؼ�ͷ������
      m_tab.InsertItem(3,L"ʶ�� ");
      //��������ҳ��ҳ
      page1.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB1));
      page2.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB1));
      page3.Create(IDD_DIALOG4,GetDlgItem(IDC_TAB1));       
      //����ҳ���λ����m_tab�ؼ���Χ��
      CRect rect;
      m_tab.GetClientRect(&rect);//��ȡ���Ի������������
      rect.top+=25; //�ӶԻ���������꣬ԭʼΪ0
      rect.bottom-=4; //�ӶԻ���������꣬ԭʼΪ����ĸ�
      rect.left+=4; //�ӶԻ���������꣬ԭʼΪ0
      rect.right-=4; //�ӶԻ���������꣬ԭʼΪ����Ŀ�
      page1.MoveWindow(&rect);
      page2.MoveWindow(&rect);   
      page3.MoveWindow(&rect);
      page1.ShowWindow(TRUE);
      m_tab.SetCurSel(0); //��ǰѡ��(�ڼ���ѡ���������0--2)��int SetCurSel( int nSelect );nSelectָ��Ҫѡ�е��ַ������±�



	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CmfcxxklDlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	 int CurSel;
     CurSel=m_tab.GetCurSel();
        switch(CurSel)
        {

        case 0:
                 page1.ShowWindow(TRUE);
                 page2.ShowWindow(FALSE);
                 page3.ShowWindow(FALSE);
                 break;
        case 1:
                 page1.ShowWindow(FALSE);
                 page2.ShowWindow(TRUE);
                 page3.ShowWindow(FALSE);
                 break;
        case 2:
                 page1.ShowWindow(FALSE);
                 page2.ShowWindow(FALSE);
                 page3.ShowWindow(TRUE);
                 break;
        default: ;
        }
	*pResult = 0;
}
