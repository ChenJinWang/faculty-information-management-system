#include "stdafx.h"
#include "CGTeacher.h"

extern CStringArray g_lstGroups;

CCGTeacher::CCGTeacher(void)
{
	m_strName = _T("Unknown");
	m_bMale = TRUE;
	m_strJobNo = _T("0000");
	m_strPhoneNo = _T("88888888");
	m_strJobTitle = _T("unknown");
	m_strHead=_T("");
}

CCGTeacher::CCGTeacher(CString strName,BOOL bMale, CString strPhoneNo,CString strJobNo,CString strJobTitle, int iGroupNo)
	: m_strName(strName),m_bMale(bMale),m_strPhoneNo(strPhoneNo),m_strJobNo(strJobNo),m_strJobTitle(strJobTitle),m_iGroupNo(iGroupNo)
{
	
}
CCGTeacher::~CCGTeacher(void)
{
}

	void  CCGTeacher::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar<<m_strName;
		ar<<m_bMale;
		ar<<m_strPhoneNo;
		ar<<m_strJobNo;
		ar<<m_strJobTitle;
		ar<<m_iGroupNo;
		ar<<m_strHead;
		

	}else{
		ar>>m_strName;
		ar>>m_bMale;
		ar>>m_strPhoneNo;
		ar>>m_strJobNo;
		ar>>m_strJobTitle;
		ar>>m_iGroupNo;
		ar>>m_strHead;
		
	}

	}
CString CCGTeacher::GetGroupName(){

	if (m_iGroupNo<0 || m_iGroupNo >= g_lstGroups.GetSize())
	{
		return _T("");
	}

	return g_lstGroups[m_iGroupNo];
}


