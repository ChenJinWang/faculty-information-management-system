#pragma once
class CCGTeacher
{
public:
	
	CCGTeacher(void);
	CCGTeacher(CString strName, BOOL bMale = TRUE, CString strPhoneNo = _T("88888888"), 
		CString strJobNo = _T("0000"), CString strJobTitle = _T("0000000000"),int iGroupNo = 0);
	~CCGTeacher(void);

public:
	CString          GetName()                          { return m_strName;            }
	BOOL             IsMale()                           { return m_bMale;              }
	CString          GetPhoneNo()                       { return m_strPhoneNo;         }
	CString          GetJobNo()                         { return m_strJobNo;           }
	CString          GetJobTitle()                      { return m_strJobTitle;        }
	int              GetGroupNo()                       { return m_iGroupNo;           }
	CString          GetGroupName();
	CString          GetImageHead()                     { return m_strHead;            }

	void             SetName(CString strName)           { m_strName = strName;         }
	void             SetMale(BOOL bMale)                { m_bMale = bMale;             }
	void             SetPhoneNo(CString strPhoneNo)     { m_strPhoneNo = strPhoneNo;   }
	void             SetJobNo(CString strJobNo)         { m_strJobNo = strJobNo;       }
	void             SetJobTitle(CString strJobTitle)   { m_strJobTitle = strJobTitle; }
	void             SetGroupNo(int iGroupNo)           { m_iGroupNo = iGroupNo;       }
	void             SetImageHead(CString strHead)      { m_strHead =strHead;          }

protected:
	CString          m_strName;                   //����
	BOOL             m_bMale;                     //�Ա�  TRUE��ʾ��    FALSE��ʾŮ
	CString          m_strPhoneNo;                //�绰
	CString          m_strJobNo;                  //����
	CString          m_strJobTitle;               //ְ��
	int              m_iGroupNo;                  //���飨����ϵ����
	CString          m_strHead;                  //ͷ�񣺴洢ͷ��ͼƬ��·��
public:
	void Serialize(CArchive& ar);
	

};

