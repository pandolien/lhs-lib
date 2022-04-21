#include "stdafx.h"
#include "PTRList.h"
#include <string.h>

CPTRList::CPTRList()
{
	Init();
}

void CPTRList::Init()
{
	pTop = pEnd = pCur = NULL;;
	nCurrentBlk	= -1;
	nMax		= 0;
}

CPTRList::~CPTRList()
{
	Close();
}

void CPTRList::Close()
{
	RemoveAll2();
}

void CPTRList::AddTail( void *pData )
{
    PTR_BLK *pNew = new PTR_BLK;
	pNew->pData	= pData;
	pNew->pNext	= NULL;

	if ( pEnd )	
	{
		pNew->pPrev	= pEnd;
		pEnd->pNext	= pNew;
	}
	else		pNew->pPrev	= NULL;
	
	if ( pTop==NULL )	pTop	= pNew;
	pEnd	= pNew;	
	nMax++;
}

void CPTRList::AddHead( void *pData )
{
	PTR_BLK *pNew	= new PTR_BLK;
	pNew->pData	= pData;
	pNew->pPrev	= NULL;

	if ( pTop )	
	{
		pNew->pNext	= pTop;
		pTop->pPrev	= pNew;
	}
	else		pNew->pNext	= NULL;

	if ( pEnd==NULL )	pEnd= pNew;
	pTop	= pNew;	
	nMax++;
	nCurrentBlk	= -1;
}

void CPTRList::AddTail( char *p)
{
	int n = strlen(p)+1;
	char *pNew	= new char[n];
	memmove( pNew,p,n);
	CPTRList::AddTail((void*)pNew);
}

void CPTRList::AddHead( char *p)
{
	int n = strlen(p) + 1;
	char *pNew = new char[n];
	memmove(pNew, p, n);
	CPTRList::AddHead((void*)pNew);
}

PTR_BLK* CPTRList::GetHead()
{	
	return pTop;
}

PTR_BLK* CPTRList::GetTail()
{
	return pEnd;	
}

void CPTRList::RemoveAt2( int n )
{
	if ( !GetAt(n) )	return;

	if ( pCur==pTop )
	{
		pCur	= pTop->pNext;
		if ( pTop->pData )	delete pTop->pData;
		delete pTop;

		pTop	= pCur;
		if ( pTop )		pTop->pPrev	= NULL;
	}
	else if ( pCur==pEnd)
	{
		pCur	= pEnd->pPrev;
		if ( pEnd->pData )	delete pEnd->pData;
		delete pEnd;

		pEnd	= pCur;
		if ( pEnd )		pEnd->pNext	= NULL;
	}
	else
	{
		pCur->pPrev->pNext	= pCur->pNext;
		pCur->pNext->pPrev	= pCur->pPrev;
		
		PTR_BLK	*pTemp = pCur->pNext;
		if ( pCur->pData )	delete (pCur->pData);
		delete pCur;
		
		pCur = pTemp;
	}

	nCurrentBlk	= -1;
	nMax--;
	if ( nMax<0 )	nMax = 0;

	if ( nMax==0 )	
		pEnd		= NULL;
}

void CPTRList::RemoveAt( int n ,BOOL bSelfDestroy)
{
	if ( !GetAt(n) )	return;

	if ( pCur==pTop )
	{
		pCur	= pTop->pNext;
		
		if ( bSelfDestroy)
		if ( pTop->pData )	delete pTop->pData;
		delete pTop;

		pTop	= pCur;
		if ( pTop )		pTop->pPrev	= NULL;
	}
	else if ( pCur==pEnd)
	{
		pCur	= pEnd->pPrev;
		if ( bSelfDestroy)
		if ( pEnd->pData )	delete pEnd->pData;
		delete pEnd;

		pEnd	= pCur;
		if ( pEnd )		pEnd->pNext	= NULL;
	}
	else
	{
		pCur->pPrev->pNext	= pCur->pNext;
		pCur->pNext->pPrev	= pCur->pPrev;
		
		PTR_BLK	*pTemp = pCur->pNext;
		if ( bSelfDestroy)
		if ( pCur->pData )	delete (pCur->pData);
		delete pCur;
		
		pCur = pTemp;
	}

	nCurrentBlk	= -1;
	nMax--;
	if ( nMax<0 )	nMax = 0;
	if ( nMax==0 )	
		pEnd		= NULL;
}

void CPTRList::RemoveAt(void *p,BOOL bSelfDestroy)
{
	for (int i=0;i<GetCount();i++)
	{
		void *pData = Search(i);
		if (pData==p)	RemoveAt(i--,bSelfDestroy);
	}
}

void* CPTRList::GetAt( int n)
{
	int nCnt = 0;
	PTR_BLK *pBlk = pCur = pTop;

	if ( n>=GetCount() )	return NULL;

	nCurrentBlk	= n;

	while(pBlk!=NULL)
	{
		if ( n==nCnt )	return pBlk->pData;
		nCnt++;
		pBlk	= pCur = pBlk->pNext;
	}
	
	nCurrentBlk = -1;
	return NULL;
}

void* CPTRList::Search( int n )
{
	if ( n<0)	return NULL;
	if ( nCurrentBlk<0  )	return GetAt(n);
	if ( n>=nMax )	return NULL;
	
	if (pCur==NULL)	return GetAt(n);
	
	if ( nCurrentBlk-n==-1 )	
	{		
		nCurrentBlk = n;
		pCur = pCur->pNext;
		if (pCur==NULL)	return GetAt(n);
		return pCur->pData;
	}
	if ( nCurrentBlk-n==1 )	
	{
		nCurrentBlk = n;
		pCur = pCur->pPrev;
		if (pCur==NULL)	return GetAt(n);
		return pCur->pData;
	}
	if ( nCurrentBlk-n==0 )	
	{
		nCurrentBlk = n;
		if (pCur==NULL)	return GetAt(n);
		return pCur->pData;
	}
	
	return GetAt(n);
}

int CPTRList::GetCount()
{
	return nMax;
}

void CPTRList::RemoveAll2()
{
	PTR_BLK *pTemp;

	pCur = pTop;
	while( pCur)
	{
		pTemp	= pCur->pNext;
		if ( pCur->pData )	delete (pCur->pData);
		delete pCur;

		pCur	= pTemp;
	}

	pCur	= NULL;
	pTop	= NULL;
	pEnd	= NULL;
	nMax	= 0;
	nCurrentBlk	= -1;
}

void CPTRList::RemoveAll(BOOL bSelfDestroy)
{
	if ( bSelfDestroy==FALSE)
	{
		PTR_BLK *pTemp;

		pCur = pTop;
		while( pCur)
		{
			pTemp	= pCur->pNext;
			delete pCur;

			pCur	= pTemp;
		}

		pCur	= NULL;
		pTop	= NULL;
		pEnd	= NULL;
		nMax	= 0;
		nCurrentBlk	= -1;
	}
	else
		CPTRList::RemoveAll2();
}

BOOL CPTRList::IsEmpty()
{
	return nMax>0 ? TRUE:FALSE;
}

void CPTRList::InsertAfter( int n,void *pData)
{
	if ( n<0 )	
	{
		AddHead(pData);
		return ;
	}
	if ( n==GetCount()-1)	
	{
		AddTail(pData);
		return;
	}
	
	GetAt(n);
	nCurrentBlk	= -1;

	PTR_BLK *pNew	= new PTR_BLK;
	pNew->pData		= pData;
	pNew->pPrev		= pCur;
	pNew->pNext		= pCur->pNext;

	pCur->pNext->pPrev	= pNew;
	pCur->pNext		= pNew;
	nMax++;
}

void CPTRList::InsertAfter( void *pData )
{
	if ( pCur==pEnd )	
	{
		AddTail( pData );
		return;
	}

	PTR_BLK *pNew	= new PTR_BLK;
	pNew->pData		= pData;
	pNew->pPrev		= pCur;
	pNew->pNext		= pCur->pNext;

	pCur->pNext->pPrev	= pNew;
	pCur->pNext		= pNew;
	nMax++;
}

void CPTRList::InsertBefore( int n,void *pData)
{
	if ( n<0 )	
	{
		AddTail(pData);
		return;
	}
	if ( n==0 )		
	{
		AddHead(pData);
		return ;
	}
	
	GetAt(n);
	nCurrentBlk	= -1;

	PTR_BLK *pNew	= new PTR_BLK;
	pNew->pData		= pData;
	pNew->pPrev		= pCur->pPrev;
	pNew->pNext		= pCur;

	pCur->pPrev->pNext	= pNew;
	pCur->pPrev		= pNew;
	nMax++;
}

void CPTRList::InsertBefore( void *pData)
{
	if ( pCur==pTop )		
	{
		AddHead(pData);
		return ;
	}
	
	PTR_BLK *pNew	= new PTR_BLK;
	pNew->pData		= pData;
	pNew->pPrev		= pCur->pPrev;
	pNew->pNext		= pCur;

	pCur->pPrev->pNext	= pNew;
	pCur->pPrev		= pNew;
	nMax++;
}

void* CPTRList::operator [](int n)
{
	return Search(n);
}

int CPTRList::FindData(void *p)
{
	void *pData;
	for (int i=0;i<GetCount();i++)
	{
		pData = Search(i);
		if ( pData==p )	return i;
	}
	return -1;
}

/*
void CPTRList::Load(char *psz,int n)
{
	FILE *fp	= fopen(psz,"rb");
	if ( fp==NULL)	return;
	int cnt;
	fread( &cnt,sizeof(int),1,fp);

	for(int i=0;i<cnt;i++)
	{
		BYTE *p = new BYTE[n];
		fread( p,n,1,fp);
		AddTail(p);
	}
	fclose(fp);
}

void CPTRList::Save(char *psz,int n)
{
	FILE *fp	= fopen(psz,"wb");
	if ( fp==NULL)	return;
	int cnt = GetCount();
	fwrite( &cnt,sizeof(int),1,fp);
	for(int i=0;i<GetCount();i++)
	{
		void *p = Search(i);
		fwrite( p,n,1,fp);
	}
	fclose(fp);
}
*/
void* CPTRList::Prev(int n)
{
	PTR_BLK *p = pCur;
	for (int i=0;i<n;i++)
	{
		p	= p->pPrev;
		if ( p==NULL)	return NULL;
	}

	return p->pData;
}

void* CPTRList::Next(int n)
{
	PTR_BLK *p = pCur;
	for (int i=0;i<n;i++)
	{
		p	= p->pNext;
		if ( p==NULL)	return NULL;
	}

	return p->pData;
}



CRectList::CRectList()
{
}

CRectList::~CRectList()
{
	RemoveAll2();
}

void CRectList::Add(CRect& rect)
{
	CRect *pNew	= new CRect(rect);
	CPTRList::AddTail(pNew);
}

CRect CRectList::Search(int n)
{
	CRect *p	= (CRect*)CPTRList::Search(n);

	CRect ret(0,0,0,0);
	if ( p==NULL )	return ret;
	return *p;
}

