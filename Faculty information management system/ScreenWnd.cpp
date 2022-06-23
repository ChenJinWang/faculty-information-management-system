// ScreenWnd.cpp: implementation of the CScreenWnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Resource.h"
#include "ScreenWnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CScreenWnd::CScreenWnd()
{
  	m_bitmap.LoadBitmap(IDB_BITMAP2);//������Դλͼ
	
    m_bitmap.GetBitmap(&bm);//�õ�λͼ�ṹ�еĴ�С��Ϣ
}

CScreenWnd::~CScreenWnd()
{

}

void CScreenWnd::CreatScreenWnd()
{
	//������С��λͼ��С��ͬ�Ĵ���
	CreateEx(0,AfxRegisterWndClass(0,AfxGetApp()->LoadStandardCursor(IDC_ARROW)),
		_T("ImageScreen"),
		WS_POPUP,
		0,0,bm.bmWidth,bm.bmHeight,
		NULL,
		NULL,
		NULL );
}

BEGIN_MESSAGE_MAP(CScreenWnd, CWnd)
//{{AFX_MSG_MAP(CScreenWnd)
ON_WM_PAINT()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScreenWnd message handlers

void CScreenWnd::OnPaint() 
{
	CPaintDC dc(this); // device context for painting	
	// TODO: Add your message handler code here
	MemDC.CreateCompatibleDC(NULL);//����һ����dc���ݵ��ڴ�DC����λͼ
	old_bitmap=MemDC.SelectObject(&m_bitmap);//��������λͼѡ���ڴ�DC
	int i,j,stepx,stepy,dispnum,x,y; 
	int lwf[20][20];      //�����¼����ʾ���������� 	
	for ( i=0; i<20; i++ ) 		
		for ( j=0; j<20; j++ ) 			
			lwf[i][j]=0; 		
		stepx=bm.bmWidth/20; 
		stepy=bm.bmHeight/20; 
		srand( (unsigned)time( NULL ) ); 		
		dispnum=0; 	
		//��¼����ʾ����������ĸ��� 		
		while(1) 			
		{ x=rand() % 20; 		
		  y=rand() % 20; 		
		if ( lwf[x][y] ) //���Ϊ1�����Ѿ���ʾ�ˣ�����ѭ����			
			continue; 	
		lwf[x][y]=1; //��ʾ������Ϊ1				
		dc.StretchBlt(x*stepx, y*stepy, //Ŀ���豸�߼��ᡢ������ 
				   	       stepx,stepy, //��ʾλͼ�����ؿ��߶� 
			&MemDC, //λͼ�ڴ��豸���� 
					  x*stepx, y*stepy, //λͼ����ʼ�ᡢ������ 
					       stepx,stepy, //λͼ�����ؿ��߶� 
			SRCCOPY); 		
		dispnum++; 		
		if ( dispnum >=400 ) 			
			break; 		
		Sleep(10); 		
		}		
		MemDC.SelectObject(old_bitmap);
		// Do not call CWnd::OnPaint() for painting messages
}
