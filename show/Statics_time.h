#if !defined(AFX_STATICS_TIME_H__36F460F8_C95F_4A48_BA2E_655C02EB4504__INCLUDED_)
#define AFX_STATICS_TIME_H__36F460F8_C95F_4A48_BA2E_655C02EB4504__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Statics_time.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Statics_time dialog

typedef struct
{
	long index;
	unsigned short year;
	unsigned char month,day,hour,minte,second;
	char name[10];
	char message[30];
	char banhao;
	unsigned short  qdxxq[40] , dcbsq[30];
	unsigned short  xhbsq[40] , dcztq[30]; 
	unsigned short  dcflag[15];
	unsigned short  xhflag[15];
	unsigned short  flagq50; //64d
} RecordStru;

class Statics_time : public CDialog
{
// Construction
public:
	Statics_time(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Statics_time)
	enum { IDD = IDD_TIME };
	CComboBox	m_CtrlCombo;
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Statics_time)
	protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Statics_time)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int GetParaValue();
private:
	
	RecordStru** ReadData(CString file_path);
	void Check(RecordStru** p_data);
	int m_actualNumb;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICS_TIME_H__36F460F8_C95F_4A48_BA2E_655C02EB4504__INCLUDED_)
