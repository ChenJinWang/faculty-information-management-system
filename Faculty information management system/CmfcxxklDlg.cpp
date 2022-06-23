// CmfcxxklDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "CmfcxxklDlg.h"
#include "afxdialogex.h"


// CmfcxxklDlg 对话框

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


// CmfcxxklDlg 消息处理程序


BOOL CmfcxxklDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	  //初始化m_tab控件
      m_tab.InsertItem(1,L"预处理 ");//在字符串前加’L‘来转变类型
      m_tab.InsertItem(2,L"检测 ");//int InsertItem( int nItem,LPCTSTR lpszItem );其中，nItem是控件中行的索引、lpszItem是控件头的名字
      m_tab.InsertItem(3,L"识别 ");
      //建立属性页各页
      page1.Create(IDD_DIALOG2,GetDlgItem(IDC_TAB1));
      page2.Create(IDD_DIALOG3,GetDlgItem(IDC_TAB1));
      page3.Create(IDD_DIALOG4,GetDlgItem(IDC_TAB1));       
      //设置页面的位置在m_tab控件范围内
      CRect rect;
      m_tab.GetClientRect(&rect);//获取父对话框的区域坐标
      rect.top+=25; //子对话框的上坐标，原始为0
      rect.bottom-=4; //子对话框的下坐标，原始为区域的高
      rect.left+=4; //子对话框的左坐标，原始为0
      rect.right-=4; //子对话框的右坐标，原始为区域的宽
      page1.MoveWindow(&rect);
      page2.MoveWindow(&rect);   
      page3.MoveWindow(&rect);
      page1.ShowWindow(TRUE);
      m_tab.SetCurSel(0); //当前选项(第几个选项卡，共三个0--2)，int SetCurSel( int nSelect );nSelect指定要选中的字符串的下标



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
