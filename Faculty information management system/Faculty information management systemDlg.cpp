
// Faculty information management systemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Faculty information management system.h"
#include "Faculty information management systemDlg.h"
#include "afxdialogex.h"
#include "GEditDlg.h"
#include "ScreenWnd.h"
#include "BtnST.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Loging.h"
#include <Vfw.H>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
#include "CmfcxxklDlg.h"
#include "SuperChartDlg.h"

#include"CApplication.h"
#include"CRange.h"
#include"CWorkbook.h"
#include"CWorkbooks.h"
#include"CWorksheet.h"
#include"CWorksheets.h"
#include"CFont0.h"
#include"PictureEx.h"


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_SHOWWINDOW()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CFacultyinformationmanagementsystemDlg 对话框



CFacultyinformationmanagementsystemDlg::CFacultyinformationmanagementsystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFacultyinformationmanagementsystemDlg::IDD, pParent)
	, m_strFind(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFacultyinformationmanagementsystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LST_TEACHER, m_lstcGPersonList);
	DDX_Text(pDX, IDC_ED_FIND, m_strFind);
	DDX_Control(pDX, IDC_BTN_ADD, m_addBtn);
	DDX_Control(pDX, IDC_BTN_EDIT, m_editBtn);
	DDX_Control(pDX, IDC_BTN_DEL, m_delBtn);
	DDX_Control(pDX, IDC_BTN_OPEN, m_openBtn);
	DDX_Control(pDX, IDC_BTN_SAVE, m_saveBtn);
	DDX_Control(pDX, IDC_BTN_ADD, m_addBtn);
	DDX_Control(pDX, IDC_BTN_EDIT, m_editBtn);
	DDX_Control(pDX, IDC_BTN_DEL, m_delBtn);
	DDX_Control(pDX, IDC_BTN_OPEN, m_openBtn);
	DDX_Control(pDX, IDC_BTN_SAVE, m_saveBtn);
	DDX_Control(pDX, IDC_STA_GIF, m_gifpicture);
}

BEGIN_MESSAGE_MAP(CFacultyinformationmanagementsystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ADD, &CFacultyinformationmanagementsystemDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_DEL, &CFacultyinformationmanagementsystemDlg::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_EDIT, &CFacultyinformationmanagementsystemDlg::OnBnClickedBtnEdit)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CFacultyinformationmanagementsystemDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CFacultyinformationmanagementsystemDlg::OnBnClickedBtnOpen)
	ON_WM_DESTROY()
	ON_EN_CHANGE(IDC_ED_FIND, &CFacultyinformationmanagementsystemDlg::OnChangeEdFind)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LST_TEACHER, &CFacultyinformationmanagementsystemDlg::OnItemchangedLstTeacher)
	ON_COMMAND(IDM_SAVE, &CFacultyinformationmanagementsystemDlg::OnSave)
	ON_COMMAND(IDM_OPEN, &CFacultyinformationmanagementsystemDlg::OnOpen)
	ON_COMMAND(IDM_EXIT, &CFacultyinformationmanagementsystemDlg::OnExit)
	ON_COMMAND(ID_32774, &CFacultyinformationmanagementsystemDlg::On32774)
	ON_COMMAND(IDM_ADD, &CFacultyinformationmanagementsystemDlg::OnAdd)
	ON_COMMAND(IDM_EDIT, &CFacultyinformationmanagementsystemDlg::OnEdit)
	ON_COMMAND(IDM_ABOUT, &CFacultyinformationmanagementsystemDlg::OnAbout)
	ON_COMMAND(ID_TOOLBTN_ADD, &CFacultyinformationmanagementsystemDlg::OnToolbtnAdd)
	ON_COMMAND(ID_TOOLBTN_EDIT, &CFacultyinformationmanagementsystemDlg::OnToolbtnEdit)
	ON_COMMAND(ID_TOOLBTN_DELETE, &CFacultyinformationmanagementsystemDlg::OnToolbtnDelete)
	ON_COMMAND(ID_TOOLBTN_ABOUT, &CFacultyinformationmanagementsystemDlg::OnToolbtnAbout)
	ON_WM_LBUTTONDOWN()
	ON_WM_CONTEXTMENU()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LST_TEACHER, &CFacultyinformationmanagementsystemDlg::OnCustomdrawLstTeacher)
	ON_WM_CTLCOLOR()
//	ON_WM_SIZE()
ON_WM_SIZE()
ON_COMMAND(IDM_FIND, &CFacultyinformationmanagementsystemDlg::OnFind)
ON_BN_CLICKED(IDC_BTN_FIND, &CFacultyinformationmanagementsystemDlg::OnBnClickedBtnFind)
ON_BN_CLICKED(IDC_BUTTON2, &CFacultyinformationmanagementsystemDlg::OnBnClickedButton2)
ON_WM_TIMER()
ON_BN_CLICKED(IDC_BTN_SUPER, &CFacultyinformationmanagementsystemDlg::OnBnClickedBtnSuper)
ON_COMMAND(ID_32796, &CFacultyinformationmanagementsystemDlg::On32796)
END_MESSAGE_MAP()


// CFacultyinformationmanagementsystemDlg 消息处理程序

BOOL CFacultyinformationmanagementsystemDlg::OnInitDialog()
{
	CLoging  login;
	
	while (true)
	{
		int iRet = login.DoModal();
		if (iRet != IDOK)
		{
			exit(0);
		}
		if (login.m_strZhangHao == L"007" && login.m_strMiMa == L"12345") 
		{
			MessageBox(L"登录成功！");
		WCHAR szCurPath[_MAX_PATH];	//获取默认通信录文件名
	GetCurrentDirectory(MAX_PATH, szCurPath);

	HWND hMCI;
CString choose = CString(szCurPath);  //音乐文件的路径 
choose.Format(_T("%s\\music.mp3"), szCurPath);  //音乐文件名
hMCI = MCIWndCreate(NULL, NULL,WS_POPUP|MCIWNDF_NOPLAYBAR|MCIWNDF_NOMENU,choose);  
	MCIWndPlay(hMCI); //播放音乐


			//if (login.m_strAdmin ==L"hy")
			//{
			//	GetDlgItem(IDC_BTN_BACKUP)->ShowWindow(FALSE);  //隐藏按钮
			//	GetDlgItem(IDC_BTN_RESTORE)->EnableWindow(FALSE); //禁用按钮
			//}

			
			break;
		}else{
			MessageBox(L"登录失败！");
		}
	}

	CDialogEx::OnInitDialog();
	if (m_gifpicture.Load(MAKEINTRESOURCE(IDR_GIF1),_T("gif")))//gif
	m_gifpicture.Draw();//gif

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);


	CScreenWnd* imageWnd = new CScreenWnd;  //建立一个新窗口对象
	imageWnd->CreatScreenWnd ();			//创建窗口
	imageWnd->CenterWindow ();				//在屏幕中央
	imageWnd->ShowWindow (SW_SHOW);			//显示窗口
	imageWnd->UpdateWindow ();				//更新窗口，激活OnPait函数

	if (imageWnd != NULL)
	{
		imageWnd->SendMessage (WM_CLOSE); //关闭窗口
	}


	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	SetTimer(1,1000,NULL);

	//图片按钮系列
	m_addBtn.SetIcon (IDI_ICON1,IDI_ICON2);//设置按钮背景
	m_delBtn.SetIcon (IDI_ICON2,IDI_ICON3);
	m_openBtn.SetIcon (IDI_ICON3,IDI_ICON4);
	m_saveBtn.SetIcon (IDI_ICON4,IDI_ICON5);
	m_editBtn.SetIcon (IDI_ICON5,IDI_ICON1);
   // m_addBtn.SetFlat (FALSE);

	//图片按钮系列
	m_addBtn.SetActiveBgColor(RGB(255,255,0));//设置激活后的背景颜色
    m_addBtn.SetDefaultInactiveFgColor(RGB(0,0,255));//设置前文本颜色
    m_addBtn.SetInactiveBgColor(RGB(255,0,255));//设置默认的背景颜色
	m_addBtn.SetAlign(CButtonST::ST_ALIGN_VERT);//设置文章对齐
	m_addBtn.SetTooltipText(&CString("添加"));//设置文章提示
	m_addBtn.SetBtnCursor(IDC_CURSOR3);//设置光标样式
	m_addBtn.DrawTransparent(TRUE);//按钮变透明

	
	m_editBtn.SetActiveBgColor(RGB(255,255,0));//设置激活后的背景颜色
    m_editBtn.SetDefaultInactiveFgColor(RGB(0,0,255));//设置前文本颜色
    m_editBtn.SetInactiveBgColor(RGB(255,0,255));//设置默认的背景颜色
	m_editBtn.SetAlign(CButtonST::ST_ALIGN_VERT);//设置文章对齐
	m_editBtn.SetTooltipText(&CString("编辑"));
	m_editBtn.SetBtnCursor(IDC_CURSOR3);
	m_editBtn.DrawTransparent(TRUE);

	
	m_openBtn.SetActiveBgColor(RGB(255,255,0));//设置激活后的背景颜色
    m_openBtn.SetDefaultInactiveFgColor(RGB(0,0,255));//设置前文本颜色
    m_openBtn.SetInactiveBgColor(RGB(255,0,255));//设置默认的背景颜色
	m_openBtn.SetAlign(CButtonST::ST_ALIGN_VERT);
	m_openBtn.SetTooltipText(&CString("打开"));
	m_openBtn.SetBtnCursor(IDC_CURSOR3);
	m_openBtn.DrawTransparent(TRUE);

	m_saveBtn.SetActiveBgColor(RGB(255,255,0));//设置激活后的背景颜色
    m_saveBtn.SetDefaultInactiveFgColor(RGB(0,0,255));//设置前文本颜色
    m_saveBtn.SetInactiveBgColor(RGB(255,0,255));//设置默认的背景颜色
	m_saveBtn.SetAlign(CButtonST::ST_ALIGN_VERT);
	m_saveBtn.SetTooltipText(&CString("保存"));
	m_saveBtn.SetBtnCursor(IDC_CURSOR3);
	m_saveBtn.DrawTransparent(TRUE);

	m_delBtn.SetActiveBgColor(RGB(255,255,0));//设置激活后的背景颜色
    m_delBtn.SetDefaultInactiveFgColor(RGB(0,0,255));//设置前文本颜色
    m_delBtn.SetInactiveBgColor(RGB(255,0,255));//设置默认的背景颜色
	m_delBtn.SetAlign(CButtonST::ST_ALIGN_VERT);
	m_delBtn.SetTooltipText(&CString("删除"));
	m_delBtn.SetBtnCursor(IDC_CURSOR3);
	m_delBtn.DrawTransparent(TRUE);

	CreateToolBar();
	InitGPersonListCtrl();

	WCHAR szCurPath[_MAX_PATH];
	GetCurrentDirectory(_MAX_PATH,szCurPath);
	m_strDefGCLFileName.Format(_T("%s\\CGTeacher.gcl"),szCurPath);
	if(PathFileExists(m_strDefGCLFileName)){
	   DoLoadFile(m_strDefGCLFileName);
	   RefreshPersonListCtrl(m_lstCGTeacher);
	}
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFacultyinformationmanagementsystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFacultyinformationmanagementsystemDlg::OnPaint()
{
				
					
	//绘制背景图片				
	CPaintDC dc(this);				
	CBitmap bitmap;				
	bitmap.LoadBitmapW(IDB_BITMAP4);				//bitmap的资源id
	CBrush brush;				
	brush.CreatePatternBrush(&bitmap);				
	CBrush* pOldBrush =dc.SelectObject(&brush);				
	CRect rect;				
	GetClientRect(&rect);				
	dc.Rectangle(&rect);				
	dc.SelectObject(pOldBrush);				

	if (m_lstCGTeacher.GetCount()!=0 &&PathFileExists(m_lstCGTeacher[GetCurSel()].GetImageHead()))
	{
		CGPersonList::ShowImage(this->m_hWnd,m_lstCGTeacher[GetCurSel()].GetImageHead(),IDC_STA_HEAD);
	}

	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFacultyinformationmanagementsystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CFacultyinformationmanagementsystemDlg::InitGPersonListCtrl(void){

	m_lstcGPersonList.SetExtendedStyle(m_lstcGPersonList.GetExtendedStyle() | 
		LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT	);

	m_lstcGPersonList.InsertColumn(0,_T("姓名"),LVCFMT_CENTER,100);
	m_lstcGPersonList.InsertColumn(1,_T("性别"),LVCFMT_CENTER,80);
	m_lstcGPersonList.InsertColumn(2,_T("手机号"),LVCFMT_CENTER,120);
	m_lstcGPersonList.InsertColumn(3,_T("工号"),LVCFMT_CENTER,120);
	m_lstcGPersonList.InsertColumn(4,_T("职称"),LVCFMT_CENTER,80);
	m_lstcGPersonList.InsertColumn(5,_T("分组"),LVCFMT_CENTER,100);
}
int CFacultyinformationmanagementsystemDlg::GetCurSel(){

	POSITION pos = m_lstcGPersonList.GetFirstSelectedItemPosition();
	return m_lstcGPersonList.GetNextSelectedItem(pos);
}
void CFacultyinformationmanagementsystemDlg::RefreshPersonListCtrl(CGPersonList& psnList,int iCurSel)
{
	int iLastSel = GetCurSel();
	m_lstcGPersonList.DeleteAllItems();

	for (int i = 0; i < psnList.GetSize(); i++)
	{
		m_lstcGPersonList.InsertItem(i,psnList[i].GetName());
		m_lstcGPersonList.SetItemText(i,1,psnList[i].IsMale()?_T("女"):_T("男"));
		m_lstcGPersonList.SetItemText(i,2,psnList[i].GetPhoneNo());
		m_lstcGPersonList.SetItemText(i,3,psnList[i].GetJobNo());
		m_lstcGPersonList.SetItemText(i,4,psnList[i].GetJobTitle());
		m_lstcGPersonList.SetItemText(i,5,psnList[i].GetGroupName());
	}

	if (iCurSel<0)
	{
		if (iLastSel<0)
		{
			iCurSel = psnList.GetSize() >0 ?0:-1;
		}else{
		
			iCurSel = min(psnList.GetSize()-1,iLastSel);
		}
	}else{
	
		iCurSel = min(psnList.GetSize()-1,iCurSel);
	}

	if (iCurSel>=0)
	{
		m_lstcGPersonList.SetFocus();
		m_lstcGPersonList.SetItemState(iCurSel,LVIS_SELECTED,LVIS_SELECTED);
	}
	if (m_lstCGTeacher.GetCount()!=0 &&PathFileExists(m_lstCGTeacher[GetCurSel()].GetImageHead()))
	{
		CGPersonList::ShowImage(this->m_hWnd,m_lstCGTeacher[GetCurSel()].GetImageHead(),IDC_STA_HEAD);
	}
	CountMale();
}


void CFacultyinformationmanagementsystemDlg::OnBnClickedBtnAdd()
{
	//MessageBox(L"ok");
	//1 导入子对话框的头文件  2 建立子对话框的对象  3 调用domodal
	CCGTeacher psnDef;
    CGEditDlg  dlgEdit(psnDef,this);
	int iRet = dlgEdit.DoModal();
	if (iRet == IDOK)
	{
		m_lstCGTeacher.Add(dlgEdit.GetCGTeacher());
		RefreshPersonListCtrl(m_lstCGTeacher,m_lstCGTeacher.GetSize()-1);
		
	}
}


void CFacultyinformationmanagementsystemDlg::OnBnClickedBtnDel()
{
	POSITION pos = m_lstcGPersonList.GetFirstSelectedItemPosition();
	if (pos == NULL)
	return ;
	else
	{
		if (MessageBox(_T("小子你想删除联系人吗？"),_T("确认删除"),MB_YESNO|MB_ICONERROR) == IDYES)
		{
			int n=0; //n代表列表与动态数组的差值
			while (pos)
			{
				int nItem = m_lstcGPersonList.GetNextSelectedItem(pos);
				
				m_lstCGTeacher.RemoveAt(nItem-n);
				n++;
			}
			RefreshPersonListCtrl(m_lstCGTeacher,0);
		}
		
	}

}


void CFacultyinformationmanagementsystemDlg::OnBnClickedBtnEdit()
{
	int iCurSel = GetCurSel();
	if (iCurSel<0) return;
	CGEditDlg  dlgEdit(m_lstCGTeacher[iCurSel],this);
	int iRet = dlgEdit.DoModal();
	if (iRet == IDOK)
	{
		m_lstCGTeacher[iCurSel] = dlgEdit.GetCGTeacher();
		RefreshPersonListCtrl(m_lstCGTeacher,iCurSel);
		
	}
}


BOOL CFacultyinformationmanagementsystemDlg::DoSaveFile(CString strFileName)
{
	CFile fileGCL(strFileName,CFile::modeWrite | CFile::modeCreate);
	CArchive ar(&fileGCL,CArchive::store);
	m_lstCGTeacher.Serialize(ar);
    return TRUE;
}

void CFacultyinformationmanagementsystemDlg::OnBnClickedBtnSave()
{
	CFileDialog dlgFile(FALSE,_T(".gcl"),NULL,OFN_PATHMUSTEXIST|OFN_LONGNAMES|
		OFN_HIDEREADONLY,_T("教职工信息管理系统(*.gcl)|*.gcl||"),NULL);
	if (dlgFile.DoModal()!=IDOK){
		m_lstcGPersonList.SetFocus();
		return;
	}
	DoSaveFile(dlgFile.GetPathName());
	// TODO: 在此添加控件通知处理程序代码
}

BOOL CFacultyinformationmanagementsystemDlg::DoLoadFile(CString strFileName)
{
	CFile fileGCL(strFileName,CFile::modeRead);
	CArchive ar(&fileGCL,CArchive::load);
	m_lstCGTeacher.Serialize(ar);
  return TRUE;
}


void CFacultyinformationmanagementsystemDlg::OnBnClickedBtnOpen()
{
	CFileDialog dlgFile(TRUE,_T(".gcl"),NULL,OFN_PATHMUSTEXIST|OFN_LONGNAMES|OFN_HIDEREADONLY,
		_T("教职工信息管理系统（*.gcl)|*.gcl||"),NULL);
	if (dlgFile.DoModal()!=IDOK){
		m_lstcGPersonList.SetFocus();
		return;
	}

	if (DoLoadFile(dlgFile.GetPathName()))
		RefreshPersonListCtrl(m_lstCGTeacher,0);
	// TODO: 在此添加控件通知处理程序代码
}




void CFacultyinformationmanagementsystemDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	DoSaveFile(m_strDefGCLFileName);
	// TODO: 在此处添加消息处理程序代码
}


void CFacultyinformationmanagementsystemDlg::OnChangeEdFind()

{
UpdateData(TRUE);
m_lstFindCGTeacher.RemoveAll();
for (int i=0;i<m_lstCGTeacher.GetSize();i++ ){
	CString tempMale=m_lstCGTeacher[i].IsMale()?_T("男") :_T("女");
		if(m_lstCGTeacher[i].GetName().Find(m_strFind)!=-1
			||tempMale.Find(m_strFind)!=-1
			||m_lstCGTeacher[i].GetPhoneNo().Find(m_strFind)!=-1
			||m_lstCGTeacher[i].GetJobNo().Find(m_strFind)!=-1
			||m_lstCGTeacher[i].GetGroupName().Find(m_strFind)!=-1
			||m_lstCGTeacher[i].GetJobTitle().Find(m_strFind)!=-1)
			m_lstFindCGTeacher.Add(m_lstCGTeacher[i]);
}
    if(m_lstFindCGTeacher.GetSize()>0)
		RefreshPersonListCtrl(m_lstFindCGTeacher);

	
}

CString CFacultyinformationmanagementsystemDlg::IntToString(int n){
	CString strTemp;
	strTemp.Format(_T("%d"),n);
	return strTemp;
}

void CFacultyinformationmanagementsystemDlg::CountMale(){
	int iBoy=0,iGirl=0;
	for (int i=0;i<m_lstCGTeacher.GetSize();i++){
	    if(m_lstCGTeacher[i].IsMale()==1)
			iBoy++;
		else
			iGirl++;
	}
	((CStatic*)GetDlgItem(IDC_STA_BOY))->SetWindowTextW(IntToString(iBoy));
 	((CStatic*)GetDlgItem(IDC_STA_GIRL))->SetWindowTextW(IntToString(iGirl));
}




void CFacultyinformationmanagementsystemDlg::OnItemchangedLstTeacher(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	if (pNMLV->uNewState == (LVIS_SELECTED|LVIS_FOCUSED))
	{
		if (m_lstCGTeacher.GetCount()!=0 &&PathFileExists(m_lstCGTeacher[GetCurSel()].GetImageHead()))
		{
			CGPersonList::ShowImage(this->m_hWnd,m_lstCGTeacher[GetCurSel()].GetImageHead(),IDC_STA_HEAD);
		}
	}
		*pResult = 0;

}



void CFacultyinformationmanagementsystemDlg::OnSave()
{
	OnBnClickedBtnSave();
}


void CFacultyinformationmanagementsystemDlg::OnOpen()
{
	OnBnClickedBtnOpen();
}


void CFacultyinformationmanagementsystemDlg::OnExit()
{
	CDialogEx::OnOK();
}


void CFacultyinformationmanagementsystemDlg::On32774()
{
	OnBnClickedBtnDel();
}


void CFacultyinformationmanagementsystemDlg::OnAdd()
{
	OnBnClickedBtnAdd();
}


void CFacultyinformationmanagementsystemDlg::OnEdit()
{
	OnBnClickedBtnEdit();
}


void CFacultyinformationmanagementsystemDlg::OnAbout()
{
	CAboutDlg about;
	about.DoModal();
}


void CFacultyinformationmanagementsystemDlg::OnToolbtnAdd()
{
	OnBnClickedBtnAdd();
}


void CFacultyinformationmanagementsystemDlg::OnToolbtnEdit()
{
	OnBnClickedBtnEdit();
}


void CFacultyinformationmanagementsystemDlg::OnToolbtnDelete()
{
	OnBnClickedBtnDel();
}


void CFacultyinformationmanagementsystemDlg::OnToolbtnAbout()
{
	CAboutDlg about;
	about.DoModal();
}
BOOL CFacultyinformationmanagementsystemDlg::CreateToolBar()
{
	if (!m_ToolBar.CreateEx(this,TBSTYLE_FLAT,WS_CHILD|WS_VISIBLE|CBRS_TOP|CBRS_GRIPPER|CBRS_TOOLTIPS|CBRS_FLYBY|CBRS_SIZE_DYNAMIC)||
		!m_ToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("创建工具栏失败！！！");
		return false;
	}

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);

	CImageList ImageList;
	ImageList.Create(32,32,ILC_COLOR32|ILC_MASK,7,1);
	ImageList.SetBkColor(RGB(255,255,255));

	CBitmap bm;
	int bl = bm.LoadBitmapW(IDB_BITMAP1);
	ImageList.Add(&bm,(CBitmap*)NULL);
	bm.Detach();

	m_ToolBar.GetToolBarCtrl().SetImageList(&ImageList);
	ImageList.Detach();
	return true;
}

void CFacultyinformationmanagementsystemDlg::OnLButtonDown(UINT nFlags, CPoint point)//对
{
		PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));				


	CDialogEx::OnLButtonDown(nFlags, point);
}


void CFacultyinformationmanagementsystemDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	 if (point.x == -1 && point.y == -1) 
 { 
  CRect rect; 
  GetClientRect(rect); 
  ClientToScreen(rect); 
  point = rect.TopLeft(); 
  point.Offset(5, 5); 
 } 
 CMenu menu; 
 VERIFY(menu.LoadMenu(IDR_MENU1));        //IDR_MENU1为菜单ID 
 CMenu* pPopup = menu.GetSubMenu(0); 
 ASSERT(pPopup != NULL); 
 CWnd* pWndPopupOwner = this; 
 while (pWndPopupOwner->GetStyle() & WS_CHILD)  pWndPopupOwner = pWndPopupOwner->GetParent(); 
 pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y,pWndPopupOwner);
}



void CFacultyinformationmanagementsystemDlg::OnCustomdrawLstTeacher(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVCUSTOMDRAW pLVCD = reinterpret_cast<LPNMLVCUSTOMDRAW>(pNMHDR); //pNMHDR是一个指针，大多数情况下它指向一个NMHDR结构对象 
    *pResult = CDRF_DODEFAULT;  
  
    // First thing - check the draw stage. If it's the control's pre-paint stage,   
    // then tell Windows we want messages for every item.  
    if ( CDDS_PREPAINT == pLVCD->nmcd.dwDrawStage )  
    {  
        *pResult = CDRF_NOTIFYITEMDRAW;  
    }  
    else if ( CDDS_ITEMPREPAINT == pLVCD->nmcd.dwDrawStage )  
    {  
        // This is the notification message for an item.   
    //处理，将item改变背景颜色  
        if(pLVCD->nmcd.dwItemSpec % 2 == 0 )
		{
		pLVCD->clrText = RGB(255,0 ,0);  // 设置字体颜色
        pLVCD->clrTextBk = RGB(0,255,255); // 背景色
		}else
		{
		pLVCD->clrText = RGB(0,255, 0);
        pLVCD->clrTextBk = RGB(255,0,255);
		}
              
           *pResult = CDRF_DODEFAULT;  
    }  

}


HBRUSH CFacultyinformationmanagementsystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)  
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	 if (nCtlColor == CTLCOLOR_STATIC)  
    {  
		CFont font;
		font.CreatePointFont(120,TEXT("华文彩云")); 

		if (pWnd->GetDlgCtrlID()==IDC_STA_BOY || pWnd->GetDlgCtrlID()==IDC_STA_GIRL)
		{
			pDC->SetTextColor(RGB(255, 0, 0)); 
			pDC->SetBkColor(RGB(255,250,250));
	       
		}

		if (pWnd->GetDlgCtrlID()==IDC_STATIC)
		{
			pDC->SetTextColor(RGB(255, 0, 0));  
	        pDC->SetBkMode(TRANSPARENT); 
			pDC->SelectObject(&font); //设置字体以及字号
		}
	   
        
	  return (HBRUSH)::GetStockObject(NULL_BRUSH);  
	}

	return hbr;
}


LRESULT CFacultyinformationmanagementsystemDlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)  //重绘边框
{

	



	LRESULT lResult = CDialog::DefWindowProc(message, wParam, lParam);

 

	CWnd* pWnd=this->GetParent();

//	m_hWnd = pWnd->m_hWnd;

	if (!::IsWindow(m_hWnd))

    {

        return lResult;

    }

		

	if (message==WM_MOVE||message==WM_PAINT||message==WM_NCPAINT||message==WM_NCACTIVATE ||message == WM_NOTIFY)

	{

		CDC* pWinDC = GetWindowDC();

		if (pWinDC)

        {

            DrawBorder(pWinDC);

        }

        else

        {

            ReleaseDC(pWinDC);

        }

	}

	return lResult;

	//return CDialog::DefWindowProc(message, wParam, lParam);

}


void CFacultyinformationmanagementsystemDlg::DrawBorder(CDC *pDC)

{

	if (m_hWnd )

	{

		CBrush Brush(RGB(185, 184, 182));

		CBrush* pOldBrush = pDC->SelectObject(&Brush);

 

		CRect rtWnd;

		GetWindowRect(&rtWnd);

 

		CPoint point;

		//填充顶部框架

		point.x = rtWnd.Width();

		point.y = GetSystemMetrics(SM_CYFRAME)+1;

		pDC->PatBlt(0, 0, point.x, point.y, PATCOPY);

		//填充左侧框架

		point.x = GetSystemMetrics(SM_CXFRAME);

		point.y = rtWnd.Height();

		pDC->PatBlt(0, 0, point.x, point.y, PATCOPY);

		//填充底部框架

		point.x = rtWnd.Width();

		point.y = GetSystemMetrics(SM_CYFRAME) + 1;

		pDC->PatBlt(0, rtWnd.Height()-point.y, point.x, point.y, PATCOPY);

		//填充右侧框架

		point.x = GetSystemMetrics(SM_CXFRAME);

		point.y = rtWnd.Height();

		pDC->PatBlt(rtWnd.Width()-point.x, 0, point.x, point.y, PATCOPY);

	}

}







void CFacultyinformationmanagementsystemDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	CRgn rgn;

	CRect rc;

	GetWindowRect(&rc); //获得窗口矩形

	rc -= rc.TopLeft();

	rgn.CreateRoundRectRgn(rc.left, rc.top, rc.right, rc.bottom, 50, 50); //根据窗口矩形创建一个圆角矩形最后两个是形成圆角的大小

SetWindowRgn(rgn, TRUE);
}


void CAboutDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);
  #define WM_SHOWTASK (WM_USER +1) 
}


void CFacultyinformationmanagementsystemDlg::OnFind()
{
         OnChangeEdFind();	
}


void CFacultyinformationmanagementsystemDlg::OnBnClickedBtnFind()
{
	
}


void CAboutDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));				
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CFacultyinformationmanagementsystemDlg::OnBnClickedButton2()
{
	CmfcxxklDlg  *pDlg=new CmfcxxklDlg ;

 pDlg->Create(IDD_TAB,this);

 pDlg->ShowWindow(SW_SHOW);
}


void CFacultyinformationmanagementsystemDlg::OnTimer(UINT_PTR nIDEvent)
{
	CString date,time;
	SYSTEMTIME sti;
	GetLocalTime( &sti );
	date.Format(_T("%4d年%2d月%2d日"),sti.wYear, sti.wMonth, sti.wDay);
	time.Format(_T("%d:%d:%d"), sti.wHour, sti.wMinute, sti.wSecond);
	GetDlgItem(IDC_DATE)->SetWindowText(date);  //设置显示控件
	GetDlgItem(IDC_TIME)->SetWindowText(time);	//


	CDialogEx::OnTimer(nIDEvent);
}


void CFacultyinformationmanagementsystemDlg::OnBnClickedBtnSuper()
{
	//DrawChart(0,L"柱状图",3,9,5,L"星期",L"营业额");
	CSuperChartDlg ch(arr,1,L"男女性别统计图",10,200,2,L"星期",L"营业额");
	
	ch.DoModal();
}


void CFacultyinformationmanagementsystemDlg::On32796()     //导出EXCEL表格
{
	 CString strFile = _T("E:\\Test.xls");
         COleVariant
                   covTrue((short)TRUE),
                   covFalse((short)FALSE),
                   covOptional((long)DISP_E_PARAMNOTFOUND,   VT_ERROR);
         CApplication   app;
         CWorkbooks   books;
         CWorkbook   book;
         CWorksheets   sheets;
         CWorksheet   sheet;
         CRange   range;
         CFont0   font;
 
         if (!app.CreateDispatch(_T("Excel.Application")))
         {
                   MessageBox(_T("创建失败！"));
                   return;
         }
 
         //Get   a   new   workbook.
         books = app.get_Workbooks();
         book = books.Add(covOptional);
 
         sheets = book.get_Worksheets();
         sheet = sheets.get_Item(COleVariant((short)1));
 
         ////////////////////////////////////CListCtrl控件report风格//////////////////////////////////////////////////////////
         CHeaderCtrl   *pmyHeaderCtrl;
         pmyHeaderCtrl =m_lstcGPersonList.GetHeaderCtrl();//此句取得CListCtrl控件的列表頭
 
         int   iRow,iCol;
         int   m_cols   =   pmyHeaderCtrl-> GetItemCount();
         int   m_rows = m_lstcGPersonList.GetItemCount();
         HDITEM   hdi;
         TCHAR     lpBuffer[256];
         bool       fFound   =   false;
 
         hdi.mask   =   HDI_TEXT;
         hdi.pszText   =   lpBuffer;
         hdi.cchTextMax   =   256;
         CString   colname;
         CString strTemp;
         for(iCol=0;   iCol <m_cols;   iCol++)//将列表的标题头写入EXCEL
         {
                   GetCellName(1 ,iCol + 1, colname);
                   range   =   sheet.get_Range(COleVariant(colname),COleVariant(colname));
                   pmyHeaderCtrl-> GetItem(iCol,   &hdi);
                   range.put_Value2(COleVariant(hdi.pszText));
                   int   nWidth   = m_lstcGPersonList.GetColumnWidth(iCol)/6;
                   //得到第iCol+1列  
                   range.AttachDispatch(range.get_Item(_variant_t((long)(iCol+1)),vtMissing).pdispVal,true);  
                   //设置列宽 
                   range.put_ColumnWidth(_variant_t((long)nWidth));
         }
         range   =   sheet.get_Range(COleVariant( _T("A1 ")),   COleVariant(colname));
         range.put_RowHeight(_variant_t((long)50));//设置行的高度
         font = range.get_Font();
         font.put_Bold(covTrue);
         range.put_VerticalAlignment(COleVariant((short)-4108));//xlVAlignCenter   =   -4108
 
         COleSafeArray   saRet;
         DWORD   numElements[]={m_rows,m_cols};       //5x2   element   array
         saRet.Create(VT_BSTR,   2,   numElements);
         range   =   sheet.get_Range(COleVariant( _T("A2 ")),covOptional);
         range = range.get_Resize(COleVariant((short)m_rows),COleVariant((short)m_cols));
         long   index[2];
         range   =   sheet.get_Range(COleVariant( _T("A2 ")),covOptional);
         range   =   range.get_Resize(COleVariant((short)m_rows),COleVariant((short)m_cols));
         for   (   iRow   =   1;   iRow   <=   m_rows;   iRow++)//将列表内容写入EXCEL
         {
                   for   (   iCol   =   1;   iCol   <=   m_cols;   iCol++)  
                   {
                            index[0]=iRow-1;
                            index[1]=iCol-1;
                            CString   szTemp;
                            szTemp=m_lstcGPersonList.GetItemText(iRow-1,iCol-1);
                            BSTR   bstr   =   szTemp.AllocSysString();
                            saRet.PutElement(index,bstr);
                            SysFreeString(bstr);
                   }
         }
 
         range.put_Value2(COleVariant(saRet));
 
//       Cnterior cellinterior;
//       range   =   sheet.get_Range(COleVariant( _T("A1 ")),covOptional);
//       range   =   range.get_Resize(COleVariant((short)1),COleVariant((short)m_cols));
//       books = range.get_Interior();
//       cellinterior.AttachDispatch(books);
//       cellinterior.put_ColorIndex(COleVariant((short)37));//设置EXCEL头一行的背景颜色
//       for(   iRow=1;   iRow   <=   m_rows;   iRow++)//设置EXCEL其余的背景颜色（颜色交替变换）
//       {
//                 int   state=iRow%2;
//                 CString   index;
//                 index.Format( _T("A%d "),iRow+1);
//                 range   =   sheet.get_Range(COleVariant(index),covOptional);
//                 range   =   range.get_Resize(COleVariant((short)1),COleVariant((short)m_cols));
//                 books=range.get_Interior();
//                 cellinterior.AttachDispatch(books);
//                 if(!state)
//                          cellinterior.put_ColorIndex(COleVariant((short)36));
//                 else
//                          cellinterior.put_ColorIndex(COleVariant((short)24));
//       }
 
         saRet.Detach();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
         book.SaveCopyAs(COleVariant(strFile));
//       cellinterior.ReleaseDispatch();
         book.put_Saved(true);
         book.ReleaseDispatch();  
         books.ReleaseDispatch();  
         app.Quit();
         app.ReleaseDispatch();

		// TODO: 在此添加命令处理程序代码
	}

	void CFacultyinformationmanagementsystemDlg::GetCellName(int nRow, int nCol, CString &strName)  //一个获取单元头的函数
{
         int nSeed = nCol;
         CString strRow;
         char cCell = 'A' + nCol - 1;
 
         strName.Format(_T("%c"), cCell);
 
         strRow.Format(_T( "%d "), nRow);
         strName += strRow;
}