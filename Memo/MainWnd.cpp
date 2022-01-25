#include "pch.h"
#include "MainApp.h"
#include "MainWnd.h"

const SIZE_T MAX = 10000000000 ; 
INT g_nCount = 0 ; 
INT g_bExit ; 

unsigned int __stdcall CountThread(void *pParm)
{
    WCHAR *szBuff = static_cast<WCHAR *>(pParm) ; 
    HWND hEditWnd = CMainApp::GetInstance().GetMainWnd().GetEditWnd() ; 
    HWND hMainWnd = CMainApp::GetInstance().GetMainWnd() ; 
    while(true)
    {
        if(g_bExit)
        {
            break ; 
        }
        RECT rc ; 
        GetClientRect(hMainWnd, &rc) ; 
        INT nBottom = rc.bottom - 20 ;  
        rc.top += nBottom ;
        ::GetWindowText(hEditWnd, szBuff, ::GetWindowTextLength(hEditWnd)) ;
        g_nCount = lstrlenW(szBuff) ; 
        InvalidateRect(hMainWnd, &rc, false) ; 
        UpdateWindow(hMainWnd) ; 
    }
    return 0 ;
}

CMainWnd::CMainWnd()
{
    HANDLE hHeap = GetProcessHeap() ; 
    m_szBuff = static_cast<WCHAR *>(HeapAlloc(hHeap, HEAP_ZERO_MEMORY, MAX)) ; 
}

CMainWnd::~CMainWnd()
{
    HANDLE hHeap = GetProcessHeap() ; 
    HeapFree(hHeap, HEAP_NO_SERIALIZE, m_szBuff) ; 
}

LRESULT CMainWnd::OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    bHandled = FALSE ;
    return 0 ; 
}

LRESULT CMainWnd::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    RECT rc ; 
    GetClientRect(&rc) ; 
    rc.bottom -= 20 ; 
    m_EditWnd.Create(_T("Edit"), m_hWnd, rc, NULL, WS_VSCROLL | WS_CHILD | WS_VISIBLE  | ES_MULTILINE, NULL, 1000) ; 
    HANDLE *hThread = reinterpret_cast<HANDLE *>(_beginthreadex(nullptr, 0, CountThread, m_szBuff, 0, nullptr)) ; 
    return 0 ; 
}

LRESULT CMainWnd::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    PAINTSTRUCT ps ; 
    HDC hDC = BeginPaint(&ps) ; 
    RECT rc ; 
    GetClientRect(&rc) ; 
    CString s ; 
    s.Format(_T("COUNT : %d   "), g_nCount) ; 
    TextOut(hDC, 20, rc.bottom - 18, s, s.GetLength()) ; 
    EndPaint(&ps) ; 
    return 0 ; 
}

LRESULT CMainWnd::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/)
{
    g_bExit = true ; 

    PostQuitMessage(0) ; 
    return 0 ; 
}

LRESULT CMainWnd::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    UINT nWidth = LOWORD(lParam) ; 
    UINT nHeight = HIWORD(lParam) ;
    m_EditWnd.ResizeClient(nWidth, nHeight -= 20) ; 
    return 0 ; 
}

LRESULT CMainWnd::OnChange(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bHandled)
{
    return 0 ; 
}

CWindow &CMainWnd::GetEditWnd()
{
    return m_EditWnd ; 
}

