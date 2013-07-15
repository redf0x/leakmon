/**
* Copyright(c) 2007-2008 TOSHIBA Medical Systems Corporation, All Rights
* Reserved.
*
* DumpTree.cpp - Contains Implementation of the class CDumpTreeApp
*
* @author :    Vishnu.P
* @version:    1.0            Date:  2008-06-13
*/


#include "stdafx.h"
#include "DumpTree.h"

#include "MainFrm.h"
#include "DumpTreeDoc.h"
#include "DumpTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(CDumpTreeApp, CWinApp)
//{{AFX_MSG_MAP(CDumpTreeApp)
ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
//}}AFX_MSG_MAP
// Standard file based document commands
ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
// Standard print setup command
ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


/** 
 * 
 * Constructor
 * 
 * @param       Nil
 * @return      Nil
 * @exception   Nil
 * @see         Nil
 * @since       1.0
 */
CDumpTreeApp::CDumpTreeApp()
{
}

CDumpTreeApp theApp;


/** 
 * 
 * contains Initialization routines
 * 
 * @param       Nil
 * @return      BOOL - 
 * @exception   Nil
 * @see         Nil
 * @since       1.0
 */
BOOL CDumpTreeApp::InitInstance()
{
    // Standard initialization
    // If you are not using these features and wish to reduce the size
    //  of your final executable, you should remove from the following
    //  the specific initialization routines you do not need.
    
//#ifdef _AFXDLL
//    Enable3dControls();			// Call this when using MFC in a shared DLL
//#else
//    Enable3dControlsStatic();	// Call this when linking to MFC statically
//#endif
    CoInitialize( 0 );
    // Change the registry key under which our settings are stored.
    // TODO: You should modify this string to be something appropriate
    // such as the name of your company or organization.
    SetRegistryKey(_T("Local AppWizard-Generated Applications"));
    
    LoadStdProfileSettings();  // Load standard INI file options (including MRU)
    
    // Register the application's document templates.  Document templates
    //  serve as the connection between documents, frame windows and views.
    
     CSingleDocTemplate* pDocTemplate;
     pDocTemplate = new CSingleDocTemplate(
         IDR_MAINFRAME,
         RUNTIME_CLASS(CDumpTreeDoc),
         RUNTIME_CLASS(CMainFrame),       // main SDI frame window
         RUNTIME_CLASS(CDumpTreeView));
     AddDocTemplate(pDocTemplate);
     
     // Parse command line for standard shell commands, DDE, file open
     CCommandLineInfo cmdInfo;
     ParseCommandLine(cmdInfo);
     
     // Dispatch commands specified on the command line
     if (!ProcessShellCommand(cmdInfo))
         return FALSE;
     
     // The one and only window has been initialized, so show and update it.
     m_pMainWnd->ShowWindow(SW_SHOW);
     m_pMainWnd->UpdateWindow();
    
    return TRUE;
}


/**
 * Copyright(c) 2007-2008 TOSHIBA Medical Systems Corporation, All Rights
 * Reserved.
 *
 * CAboutDlg - About Dialog Class
 *
 * @author :    Vishnu.P
 * @version:    1.0            Date:  2008-06-13
 */
class CAboutDlg : public CDialog
{
public:
    CAboutDlg();
    
    // Dialog Data
    //{{AFX_DATA(CAboutDlg)
    enum { IDD = IDD_ABOUTBOX };
    //}}AFX_DATA
    
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CAboutDlg)
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL
    
    // Implementation
protected:
    //{{AFX_MSG(CAboutDlg)
    // No message handlers
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};


/** 
 * 
 * Constructor
 * 
 * @param       Nil
 * @return      Nil
 * @exception   Nil
 * @see         Nil
 * @since       1.0
 */
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
    //{{AFX_DATA_INIT(CAboutDlg)
    //}}AFX_DATA_INIT
}


/** 
 * 
 * Data Exchange Function
 * 
 * @param       pDX  - 
 * @return      void
 * @exception   Nil
 * @see         Nil
 * @since       1.0
 */
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CAboutDlg)
    //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/** 
 * 
 * contains App command to run the dialog
 * 
 * @param       Nil
 * @return      void
 * @exception   Nil
 * @see         Nil
 * @since       1.0
 */
void CDumpTreeApp::OnAppAbout()
{
    CAboutDlg aboutDlg;
    aboutDlg.DoModal();
}


CDocument* CDumpTreeApp::OpenDocumentFile(LPCTSTR lpszFileName)
{
	
	return CWinApp::OpenDocumentFile(lpszFileName);
}
