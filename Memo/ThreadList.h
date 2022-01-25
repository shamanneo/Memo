#pragma once

class CThreadList
{
    private : 
        CAtlList<HANDLE> m_hThreads ; 
    public :
        CThreadList() ; 
        ~CThreadList() ; 
    public :
        CAtlList<HANDLE> &GetThreadList() ;
    public :
        void Add(HANDLE hThread) ; 
        void RemoveAll() ; 
        void WaitForAll() ; 
} ;

