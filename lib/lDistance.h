// lDistance.h: interface for the lDistance class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LDISTANCE_H__D09C0476_EC91_4BCC_B56E_2D2ED2F7CE83__INCLUDED_)
#define AFX_LDISTANCE_H__D09C0476_EC91_4BCC_B56E_2D2ED2F7CE83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "uMatrix.h"
class lDistance  
{
public:
	lDistance();
	virtual ~lDistance();
public:
	float DTW(uMatrix &A,uMatrix &B);
	float Euclidean(uMatrix &A,uMatrix &B);
	float Manhattan(uMatrix &A,uMatrix &B);
	float Hamming(uMatrix &A,uMatrix &B);

};

#endif // !defined(AFX_LDISTANCE_H__D09C0476_EC91_4BCC_B56E_2D2ED2F7CE83__INCLUDED_)
