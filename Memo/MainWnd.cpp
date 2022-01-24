#include "pch.h"
#include "MainWnd.h"

CMainWnd::CMainWnd()
{

}

CMainWnd::~CMainWnd()
{

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
    m_EditWnd.Create(_T("Edit"), m_hWnd, rc, NULL, WS_VSCROLL | WS_CHILD | WS_VISIBLE | ES_MULTILINE, NULL, 1000) ; 
    return 0 ; 
}

LRESULT CMainWnd::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    PAINTSTRUCT ps ; 
    HDC hDC = BeginPaint(&ps) ; 
    EndPaint(&ps) ; 
    return 0 ; 
}

LRESULT CMainWnd::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/)
{
    PostQuitMessage(0) ; 
    return 0 ; 
}

LRESULT CMainWnd::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    UINT nWidth = LOWORD(lParam) ; 
    UINT nHeight = HIWORD(lParam) ;
    m_EditWnd.ResizeClient(nWidth, nHeight) ; 
    return 0 ; 
}

LRESULT CMainWnd::OnChange(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bHandled)
{
    return 0 ;
}