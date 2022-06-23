// GEditDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "GEditDlg.h"
#include "afxdialogex.h"
#include "GPersonList.h"


// CGEditDlg 对话框

IMPLEMENT_DYNAMIC(CGEditDlg, CDialogEx)

CGEditDlg::CGEditDlg(CCGTeacher psn ,CWnd* pParent /*=NULL*/)
	: CDialogEx(CGEditDlg::IDD, pParent)
	, m_bMale(psn.IsMale())
	, m_iGroup(psn.GetGroupNo())
	, m_strJobNo(psn.GetJobNo())
	, m_strJobTitle(psn.GetJobTitle())
	, m_strName(psn.GetName())
	, m_strPhoneNo(psn.GetPhoneNo())
	, m_strHead(psn.GetImageHead())
{

}

CGEditDlg::~CGEditDlg()
{
}

void CGEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_CB_GENDAR, m_bMale);
	DDX_CBIndex(pDX, IDC_CB_GROUP, m_iGroup);
	DDX_Control(pDX, IDC_CB_GROUP, m_cbGroup);
	DDX_Text(pDX, IDC_ED_JOBNUMBER, m_strJobNo);
	DDX_Text(pDX, IDC_ED_JOBTitle, m_strJobTitle);
	DDX_Text(pDX, IDC_ED_NAME, m_strName);
	DDX_Text(pDX, IDC_ED_PHONENUMBER, m_strPhoneNo);
}


BEGIN_MESSAGE_MAP(CGEditDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CGEditDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_BROWSE, &CGEditDlg::OnBnClickedBtnBrowse)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CGEditDlg 消息处理程序


BOOL CGEditDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	for (int i = 0; i < g_lstGroups.GetSize(); i++)
	
		m_cbGroup.AddString(g_lstGroups[i]);
		UpdateData(FALSE);
	

	return TRUE;  
}


void CGEditDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	m_psnGEdit = CCGTeacher(m_strName,m_bMale,m_strPhoneNo,m_strJobNo,m_strJobTitle,m_iGroup);
	m_psnGEdit.SetImageHead(m_strHead);
	CDialogEx::OnOK();
}


void CGEditDlg::OnBnClickedBtnBrowse()
{
	CFileDialog dlgFile(TRUE,NULL,NULL,OFN_OVERWRITEPROMPT|OFN_ALLOWMULTISELECT|OFN_HIDEREADONLY,_T("Image files(*.png;*.jpg)|*.png;*.jpg|All files(*.*)|*.*||"),NULL);
	if (dlgFile.DoModal()==IDOK)
	{
		CString strPathName = dlgFile.GetPathName();
		m_strHead = dlgFile.GetFileName();

		CString strFolderPath = _T("head\\");
		if (!PathIsDirectory(strFolderPath))
		{
			CString strMsg;
			strMsg.Format(_T("指定路径\"%s\"不存在，是否创建？"),strFolderPath);
			if (AfxMessageBox(strMsg,MB_YESNO)==IDYES)
			{
				if (!CreateDirectory(strFolderPath,NULL))
				{
					strMsg.Format(_T("指定路径\"%s\"失败，是否还需要继续创建？"),strFolderPath);
					if (AfxMessageBox(strMsg,MB_YESNO)==IDYES)
					{
						return ;
					}
				}
			}
		}
		m_strHead=_T("head\\")+m_strHead;
		CopyFile(strPathName,m_strHead,TRUE);
		CGPersonList::ShowImage(this->m_hWnd,m_strHead,IDC_STA_PHOTO);

		
	}
}



void CGEditDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	if (PathFileExists(m_psnGEdit.GetImageHead()))
	{
		CGPersonList::ShowImage(this->m_hWnd,m_strHead,IDC_STA_PHOTO);
	}
}
