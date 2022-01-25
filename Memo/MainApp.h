#pragma once
#include "MainWnd.h"
#include "ThreadList.h" 

class CMainApp
{
    private :
        CMainWnd m_MainWnd ; 
        CRITICAL_SECTION m_cs ;
        CThreadList m_ThreadList ; 
    public :
        CMainApp() ; 
        ~CMainApp() ; 
    public :
        int Run(HINSTANCE hInstance, int nCmdShow) ; 
    public :
        CMainWnd &GetMainWnd() ; 
        CThreadList &GetThreadList() ; 
    public :    
        static CMainApp &GetInstance() ; 
        static void Release() ; 
} ;

