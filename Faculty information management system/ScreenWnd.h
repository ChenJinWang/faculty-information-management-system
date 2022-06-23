// ScreenWnd.h: interface for the CScreenWnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCREENWND_H__86C6DB02_4CC4_4FE7_910B_B50FFC09F633__INCLUDED_)
#define AFX_SCREENWND_H__86C6DB02_4CC4_4FE7_910B_B50FFC09F633__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CScreenWnd : public CWnd
{
// Construction
public:
	CScreenWnd();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScreenWnd)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	CDC MemDC;				// 创建内存DC
	BITMAP bm;				// 创建位图结构变量
	CBitmap m_bitmap;		// 创建位图对象
    CBitmap *old_bitmap;	// 创建位图对象指针
	void CreatScreenWnd();
	virtual ~CScreenWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CScreenWnd)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
