#include "pch.h"
#include "Resource.h"
#include "MainApp.h"

static CMainApp *g_pMainApp = nullptr ; 

CMainApp::CMainApp()
{
    InitializeCriticalSection(&m_cs) ; 
}

CMainApp::~CMainApp()
{
    DeleteCriticalSection(&m_cs) ; 
}

int CMainApp::Run(HINSTANCE hInstance, int nCmdShow)
{
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MEMO)) ;
    MSG msg ;
    m_MainWnd.Create(NULL, NULL, _T("Memo"), WS_OVERLAPPEDWINDOW, 0) ; 
    m_MainWnd.ShowWindow(nCmdShow) ; 
    m_MainWnd.UpdateWindow() ; 
    while (::GetMessage(&msg, nullptr, 0, 0)) // main message loop.
    {
        if (!::TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            ::TranslateMessage(&msg) ;
            ::DispatchMessage(&msg) ;
        }
    }
    return (int) msg.wParam ; 
}

//      getter

CMainWnd &CMainApp::GetMainWnd() 
{
    return m_MainWnd ; 
}

CThreadList &CMainApp::GetThreadList() 
{
    return m_ThreadList ; 
}

//      setter

//      static 

CMainApp &CMainApp::GetInstance() 
{
    if(g_pMainApp == nullptr)
    {
        g_pMainApp = new CMainApp ; 
    }
    return *g_pMainApp ; 
}

void CMainApp::Release()
{
    if(g_pMainApp != nullptr)
    {
        delete g_pMainApp ; 
        g_pMainApp = nullptr ; 
    }
}