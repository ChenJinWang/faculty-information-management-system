
// Faculty information management system.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFacultyinformationmanagementsystemApp:
// �йش����ʵ�֣������ Faculty information management system.cpp
//

class CFacultyinformationmanagementsystemApp : public CWinApp
{
public:
	CFacultyinformationmanagementsystemApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFacultyinformationmanagementsystemApp theApp;
extern CStringArray g_lstGroups;