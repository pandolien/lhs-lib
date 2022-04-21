// lToken.cpp: implementation of the lToken class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "lToken.h"
#include "lString.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

lToken::lToken()
{

}
lToken::lToken(lString &D)
{
	this->Data = D;
}
lToken::lToken(char *D)
{
	this->Data = D;
}
lToken::lToken(char D)
{
	this->Data = D;
}

lToken::~lToken()
{
	RemoveAll();
}
void lToken::RemoveAll(){
	int i;
	lString *Del;
	for(i = 0;i<this->Division.Getsize();i++){
		Del = (lString*)Division.Search(i);
		Del->RemoveAll();
		if(Del) delete(Del);
		Del = NULL;
	}
	Division.RemoveAll2();
}
void lToken::Split(char *D){
	int i,j,cnt = 0;
	int len = strlen(D);
	char buf[100];
	sprintf(buf,"");
	lString *pSData;
	BOOL CK = FALSE;
	RemoveAll();
	for(i = 0;i<Data.Getsize();i++){	
		for(j = 0;j < len;j++){
			if(Data.Data[i] == D[j]){
				pSData = new lString;
				buf[cnt] = '\0';
				*pSData = buf;
				Division.AddTail(pSData);
				sprintf(buf,"");
				cnt = 0;
				CK = TRUE;
				break;
			}
		}
		if(CK) continue;
		buf[cnt++] = Data.Data[i];
	}
	pSData = new lString;	
	*pSData = buf;	
	Division.AddTail(pSData);
}

void lToken::Split(char D){
	int i,cnt = 0;
	char buf[100];
	sprintf(buf,"");
	for(i = 0;i<Data.Getsize();i++){	
		if(Data.Data[i] == D){
			lString *pSData = new lString;
			int len = strlen(buf);
			buf[cnt] = '\0';
			*pSData = buf;
			Division.AddTail(pSData);
			sprintf(buf,"");
			cnt = 0;
			continue;
		}
		buf[cnt++] = Data.Data[i];
	}
	buf[cnt] = '\0';
	if(strlen(buf) == 0) return;
	lString *pSData = new lString;	
	*pSData = buf;	
	Division.AddTail(pSData);
}
lString lToken::operator [](int n){
	lString New,*N;
	N = (lString*)Division.Search(n);
	New.Temp();
	if(N == NULL) return New;
	New = *N;
	return New;
}
void lToken::operator =(lString &D){
	Data = D;
}
void lToken::operator =(char *D){
	Data = D;
}
void lToken::operator =(char D){
	Data = D;
}
int lToken::GetSize(){
	return Division.Getsize();
}