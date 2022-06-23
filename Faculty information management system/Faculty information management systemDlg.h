
// Faculty information management systemDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "GPersonList.h"
#include "btnst.h"
#include <Vfw.H>
#include <mmsystem.h>
#include "pictureex.h"
#pragma comment(lib, "WINMM.LIB")



// CFacultyinformationmanagementsystemDlg 对话框
class CFacultyinformationmanagementsystemDlg : public CDialogEx
{
// 构造
public:
	CFacultyinformationmanagementsystemDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FACULTYINFORMATIONMANAGEMENTSYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	
	


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


public:
	CListCtrl m_lstcGPersonList;
protected:
	void InitGPersonListCtrl(void);
	void RefreshPersonListCtrl(CGPersonList& psnList,int iCurSel = -1);
	int GetCurSel(void);
	BOOL  DoSaveFile(CString strFileName);
	BOOL  DoLoadFile(CString strFileName);
	void  CountMale();
	CString  IntToString(int n);
	BOOL CreateToolBar();
	void  DrawBorder(CDC*pDC);
	int arr[2];
	void   GetCellName(int nRow, int nCol, CString &strName);
protected:
	CGPersonList m_lstCGTeacher;
	CString m_strDefGCLFileName;
	CGPersonList m_lstFindCGTeacher;
	CToolBar m_ToolBar;

public:
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnEdit();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnOpen();
	afx_msg void OnDestroy();
	CString m_strFind;
	afx_msg void OnChangeEdFind();
	afx_msg void OnItemchangedLstTeacher(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSave();
	afx_msg void OnOpen();
	afx_msg void OnExit();
	afx_msg void On32774();
	afx_msg void OnAdd();
	afx_msg void OnEdit();
	afx_msg void OnAbout();
	afx_msg void OnToolbtnAdd();
	afx_msg void OnToolbtnEdit();
	afx_msg void OnToolbtnDelete();
	afx_msg void OnToolbtnAbout();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnCustomdrawLstTeacher(NMHDR *pNMHDR, LRESULT *pResult);
	
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButtonST m_addBtn;
	CButtonST m_editBtn;
	CButtonST m_delBtn;
	CButtonST m_openBtn;
	CButtonST m_saveBtn;
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFind();
	afx_msg void OnBnClickedBtnFind();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBtnSuper();
	afx_msg void On32796();
	CPictureEx m_gifpicture;
};
