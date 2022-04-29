// uOutlier.h: interface for the uOutlier class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _UOU_H_
#define _UOU_H_
#include "lLodeD.h"
#include "lPRTList.h"
#include "lDR.h"
#include "uMatrix.h"

class uOutlier  
{
public:
	uOutlier();
	virtual ~uOutlier();
public:
	lPRTList dData;
	lPRTList dPaa;
public:
	void Init();
	void RemoveAll();
	void RemoveList(lPRTList &);
	int GetSize();
public:
	uMatrix PAA(uMatrix *Dt,int n);
	void PAA_ALL();
	void PaaSave();
};

#endif // !defined(AFX_UOUTLIER_H__E2FFC2C6_909D_41A3_A6AF_F5951BFD18E8__INCLUDED_)
