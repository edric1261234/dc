; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=Statics_time
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "show.h"

ClassCount=4
Class1=CShowApp
Class2=CShowDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_TIME
Resource2=IDR_MAINFRAME
Resource3=IDD_SHOW_DIALOG
Class4=Statics_time
Resource4=IDD_ABOUTBOX
Resource5=IDD_DIALOG1

[CLS:CShowApp]
Type=0
HeaderFile=show.h
ImplementationFile=show.cpp
Filter=N

[CLS:CShowDlg]
Type=0
HeaderFile=showDlg.h
ImplementationFile=showDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_TAB1

[CLS:CAboutDlg]
Type=0
HeaderFile=showDlg.h
ImplementationFile=showDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SHOW_DIALOG]
Type=1
Class=CShowDlg
ControlCount=1
Control1=IDC_TAB1,SysTabControl32,1342181632

[DLG:IDD_TIME]
Type=1
Class=Statics_time
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_LIST2,SysListView32,1350631425
Control3=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242848
Control4=IDC_COMTYPE,combobox,1344340226
Control5=IDC_STATIC,static,1342308352

[CLS:Statics_time]
Type=0
HeaderFile=Statics_time.h
ImplementationFile=Statics_time.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_COMTYPE

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

