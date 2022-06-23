#include "stdafx.h"
#include "GPersonList.h"


CGPersonList::CGPersonList(void)
{
}


CGPersonList::~CGPersonList(void)
{
}

void  CGPersonList::Serialize(CArchive& ar)
{
	int iSize = GetSize();

	if (ar.IsStoring())
	{
		ar<<iSize;

	}else{
		ar>>iSize;
		SetSize(iSize);
	}

	for (int i = 0; i < iSize; i++)
	{
		(*this)[i].Serialize(ar);
	}

}
void  CGPersonList::ShowImage(HWND hDlg,CString pathName,int pictureId)
{
	CImage image;
	CRect rect;

	image.Load(pathName);
	HWND hWnd = GetDlgItem(hDlg,pictureId);

	GetClientRect(hWnd,&rect);
	HDC hdc = GetDC(hWnd);
	image.Draw(hdc,rect);

}
void  CGPersonList::PaintChart(HWND hDlg,int arr[],int controlId)
{
	CRect rect;
	HWND hWnd = GetDlgItem(hDlg,controlId);

	GetClientRect(hWnd,&rect);

	int dx = (rect.right-rect.left)/50;

	int dy = (rect.bottom - rect.top)/80;

	int L = rect.left,R = rect.right,T = rect.top, B = rect.bottom;

	CPaintDC dc(CWnd::FromHandle(hWnd));

	dc.MoveTo(L+dx*2,B-dy*3);
	dc.LineTo(L+dx*49,B-dy*3);

	dc.MoveTo(L+dx*49,B-dy*3);
	dc.LineTo(L+dx*48,B-dy*2);
	dc.MoveTo(L+dx*49,B-dy*3);
	dc.LineTo(L+dx*48,B-dy*4);

	dc.MoveTo(L+dx*2,B-dy*3);
	dc.LineTo(L+dx*2,B-dy*77);

	dc.MoveTo(L+dx*2,B-dy*77);
	dc.LineTo(L+dx*2-dy,B-dy*77+dx);
	dc.MoveTo(L+dx*2,B-dy*77);
	dc.LineTo(L+dx*2+dy,B-dy*77+dx);


	int x = L+dx*3;
	int y = B-dy*3;

	CString strnum;
	for (int i = 1; i <=2; i++)
	{
		CRect rc;
		rc.left = x+i*dx*15;
		rc.right = rc.left+dx*7;
		rc.bottom = y;
		rc.top = rc.bottom-dy*arr[i-1];
		dc.SetBkMode(TRANSPARENT);

		strnum.Format(_T("%dÈË"),arr[i-1]);
		dc.TextOutW((rc.left+rc.right)/2-3*dx,rc.bottom-dy*(arr[i-1]+8),strnum);

		CBrush brush;
		brush.CreateSolidBrush(RGB(100*i,200,0));
		dc.FillRect(&rc,&brush);

	}
}