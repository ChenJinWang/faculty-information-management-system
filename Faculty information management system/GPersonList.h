#pragma once

#include"afxtempl.h"
#include"CGTeacher.h"


typedef CArray<CCGTeacher,CCGTeacher>CCGTeachers;

class CGPersonList:public CCGTeachers
{
public:
	CGPersonList(void);
	~CGPersonList(void);
public:
	void Serialize(CArchive& ar);
	static void ShowImage(HWND hDlg,CString pathName,int pictureId);
	static void PaintChart(HWND hDlg,int arr[],int controlId);
};

