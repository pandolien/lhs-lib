// lLodeD.h: interface for the lLodeD class.
//
//////////////////////////////////////////////////////////////////////
#ifndef __lLodeD_h__
#define __lLodeD_h__
#include "lString.h"
#include "lToken.h"
#include "uMatrix.h"
class lLodeD  
{
public:
	lLodeD();
	lLodeD(char *D);
	virtual ~lLodeD();
public:
	lString Dt;
	lToken Dtt;
public:
	void Init(char *D);
	void RemoveAll();
	uMatrix Return();
	void Return2();
};

#endif // !defined(AFX_LLODED_H__FF827B3B_1941_44C0_B7AE_DEE696284D6B__INCLUDED_)
