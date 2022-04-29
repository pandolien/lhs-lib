// lClustering.h: interface for the lClustering class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LCLUSTERING_H__17B3BB62_69CD_42F1_B40F_205DBD7909C9__INCLUDED_)
#define AFX_LCLUSTERING_H__17B3BB62_69CD_42F1_B40F_205DBD7909C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "uMatrix.h"
#include "lDistance.h"
#include "lPRTList.h"
typedef float (lDistance::*Dis)(uMatrix &,uMatrix &);
class lClustering  
{
public:
	lClustering();
	virtual ~lClustering();
public:
	int *numData;
	lPRTList *VtData;
public:
	void RemoveAll();
public://///////Clustering Setting Function/////////
	uMatrix RandUnit(int num);
	void Add(lPRTList &);
	void RemoveList(lPRTList &);
	void kmAllDistance(lPRTList &,Dis Func);
	void kmMeanmove(lPRTList &);
public://///////Clustering Function/////////
	void KMeans(int k,int num,Dis Func);

};

#endif; // !defined(AFX_LCLUSTERING_H__17B3BB62_69CD_42F1_B40F_205DBD7909C9__INCLUDED_)
