#include "pch.h"
#include "ThreadList.h"

CThreadList::CThreadList() 
{

}

CThreadList::~CThreadList() 
{

}

CAtlList<HANDLE> &CThreadList::GetThreadList()
{
    return m_hThreads ; 
}

void CThreadList::Add(HANDLE hThread) 
{
    m_hThreads.AddTail(hThread) ; 
}

void CThreadList::RemoveAll() 
{
    HANDLE h ; 
    POSITION pos = m_hThreads.GetHeadPosition() ; 
    while(pos != NULL)
    {
        h = m_hThreads.GetNext(pos) ; 
        CloseHandle(h) ; 
    }
    m_hThreads.RemoveAll() ; 
}

void CThreadList::WaitForAll() 
{
    HANDLE *hThreads = new HANDLE[m_hThreads.GetCount()] ; 
    INT nIdx = 0 ; 
    POSITION pos = m_hThreads.GetHeadPosition() ; 
    while(pos != NULL)
    {
        hThreads[nIdx++] = m_hThreads.GetNext(pos) ; 
    }
    WaitForMultipleObjects(nIdx, hThreads, TRUE, INFINITE) ; 
    delete[] hThreads ; 
}