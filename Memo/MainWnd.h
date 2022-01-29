#pragma once

class CMainWnd : public CWindowImpl<CMainWnd> 
{
    private :
        CWindow m_EditWnd ;
        WCHAR *m_szBuff ; 
    public :
        CMainWnd() ; 
        ~CMainWnd() ; 
    public :
        DECLARE_WND_CLASS(_T("Memo"))

        BEGIN_MSG_MAP(CMainWnd)
            MESSAGE_HANDLER(WM_COMMAND, OnCommand) 
            MESSAGE_HANDLER(WM_CREATE, OnCreate)
            MESSAGE_HANDLER(WM_PAINT, OnPaint) 
            MESSAGE_HANDLER(WM_DESTROY, OnDestroy) 
            MESSAGE_HANDLER(WM_SIZE, OnSize)
            COMMAND_CODE_HANDLER(EN_CHANGE, OnChange)
        END_MSG_MAP() 
    public :
        LRESULT OnCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnChange(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL &bHandled) ;
    public :
        CWindow &GetEditWnd() ;
} ;
