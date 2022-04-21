// uOutlier.h: interface for the uOutlier class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _UOU_H_
#define _UOU_H_
#include "lLodeD.h"
#include "lPRTList.h"
#include "uMatrix.h"

class uOutlier  
{
public:
	uOutlier();
	virtual ~uOutlier();
public:
	lPRTList d_Rode;
	lPRTList d_PAA;
	lPRTList d_Mean;
public:
	void Init();
	int GetSize();
	uMatrix operator [](int n);
	void RemoveAll();
public:
	uMatrix PAA(uMatrix *Dt,int n);
	uMatrix PAAReturn(int n);
	void PAAALL();
	void PAASAVE();
	void ALLMean();
	void MeanSave();
	uMatrix PAAslide(int,int);
	void PAAALL2();
};

#endif // !defined(AFX_UOUTLIER_H__E2FFC2C6_909D_41A3_A6AF_F5951BFD18E8__INCLUDED_)
