// lkMeanClustering.h: interface for the lkMeanClustering class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LKMEANCLUSTERING_H__EE51427F_BEAE_4D0E_B6BB_9B62B4886D4E__INCLUDED_)
#define AFX_LKMEANCLUSTERING_H__EE51427F_BEAE_4D0E_B6BB_9B62B4886D4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "uMatrix.h"
class lkMeanClustering  
{
public:
	lkMeanClustering();
	virtual ~lkMeanClustering();
public:
	int *N;
	uMatrix RandUnitVt();
	void Mean();
	

};

#endif // !defined(AFX_LKMEANCLUSTERING_H__EE51427F_BEAE_4D0E_B6BB_9B62B4886D4E__INCLUDED_)
