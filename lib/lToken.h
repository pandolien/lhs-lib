// lToken.h: interface for the lToken class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _lToken_h_
#define _lToken_h_
#include "lString.h"
#include "lPRTList.h"
class lToken  
{
public:
	lToken();
	lToken(lString &D);
	lToken(char *D);
	lToken(char D);
	virtual ~lToken();
public:
	lPRTList Division;
	lString Data;
	void RemoveAll();
	int GetSize();
	void Split(char *D);
	void Split(char D);
public:
	void operator =(lString &D);
	void operator =(char *D);
	void operator =(char D);
	lString operator[] (int n);
};

#endif // !defined(AFX_LTOKEN_H__E465015F_65FE_433F_832C_298887ADBBB7__INCLUDED_)
