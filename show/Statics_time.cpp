// Statics_time.cpp : implementation file
//

#include "stdafx.h"
#include "show.h"
#include "Statics_time.h"
#include <string>
#include <map>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Statics_time dialog


Statics_time::Statics_time(CWnd* pParent /*=NULL*/)
	: CDialog(Statics_time::IDD, pParent)
{
	//{{AFX_DATA_INIT(Statics_time)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

}


void Statics_time::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Statics_time)
	DDX_Control(pDX, IDC_COMTYPE, m_CtrlCombo);
	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
	//}}AFX_DATA_MAP
}

BOOL Statics_time::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog

	
	// TODO: Add extra initialization here
	m_ListCtrl.InsertColumn(0, _T("序号"), LVCFMT_LEFT, 60, -1);
	m_ListCtrl.InsertColumn(1, _T("道岔"), LVCFMT_LEFT, 60, -1);
	m_ListCtrl.InsertColumn(2, _T("故障次数"), LVCFMT_LEFT, 60, -1);

	m_CtrlCombo.SetCurSel(2); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

BEGIN_MESSAGE_MAP(Statics_time, CDialog)
	//{{AFX_MSG_MAP(Statics_time)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Statics_time message handlers

void Statics_time::OnOK() 
{
	// TODO: Add extra validation here
	CString file_path = "d:\\StationAll\\bReStation\\backData\\backdata.mes";
	RecordStru** p_data = ReadData(file_path);
	Check(p_data);
	//CDialog::OnOK();
}


int Statics_time::GetParaValue()
{
	return 1;
}

using namespace std;

std::map<std::string, int> m_map_fail_count;

RecordStru** Statics_time::ReadData(CString file_path)
{
	RecordStru** p_data;
	FILE        *rec_file;
    if((rec_file=fopen(file_path,"rb+"))==NULL) 
	{
       AfxMessageBox("回放数据库不在，不能回放");
	   return NULL;
	}
    
	m_actualNumb = 1;
	for(int numb=0; numb <= m_actualNumb;numb++)
	{
		RecordStru*  Reco1 = new RecordStru;
		fseek(rec_file,numb*sizeof(RecordStru),0);
		fread((unsigned char*)Reco1,sizeof(RecordStru),1,rec_file);
		if(numb == 0)
		{
			if(Reco1->year != 5 )
			{
				AfxMessageBox("版本不一样,\n请用以前版本");
				Reco1->index = 0 ;
			}
			m_actualNumb  = Reco1->index;
			p_data = new RecordStru*[m_actualNumb + 1];
			delete Reco1;
			continue;
		}
		p_data[numb] = Reco1;	
	}
	
	fclose(rec_file);	
	return p_data;
}

void Statics_time::Check(RecordStru** p_data)
{
	if(p_data == NULL)
		return;
	CTime time;
	CString text;
	
	std::map<std::string, int>::iterator iter;
	for(int numb=1; numb <= m_actualNumb;numb++)
	{
		RecordStru*  Reco1 = p_data[numb];
		time = CTime::CTime(Reco1->year,Reco1->month,Reco1->day,Reco1->hour,Reco1->minte,Reco1->second);
		text = time.Format("%Y%m%d");
		std::string message = (char*)Reco1->message;
		int pos1 = message.find("挤岔");
		int pos2 = message.find("没表示");
		if(pos1 > 0 || pos2 > 0)
		{
			iter = m_map_fail_count.find(Reco1->name);
			if(iter == m_map_fail_count.end())
				m_map_fail_count[Reco1->name] = 1;
			else
				m_map_fail_count[Reco1->name] = iter->second+ 1;
		}
		delete Reco1;
	}
	int i = m_ListCtrl.GetItemCount();//获取list里面有多少行

	for(iter=m_map_fail_count.begin(); iter != m_map_fail_count.end(); iter++)
	{
		CString index;
		index.Format("%d",i+1);
		m_ListCtrl.InsertItem(i,index);
		CString name;
		name.Format("C%s", iter->first.c_str());
		m_ListCtrl.SetItemText(i,1, name);
		CString count;
		count.Format("%d", iter->second);
		m_ListCtrl.SetItemText(i,2, count);
		i++;
	}
}
