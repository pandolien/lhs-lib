// lLodeD.cpp: implementation of the lLodeD class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "lLodeD.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

lLodeD::lLodeD()
{

}
lLodeD::lLodeD(char *D){
	Init(D);
}
lLodeD::~lLodeD()
{
	RemoveAll();
}
void lLodeD::Init(char *D){
	Dt.open(D);
	Dtt = Dt;
	Dtt.Split('\n');
}
void lLodeD::RemoveAll(){
	Dt.RemoveAll();
	Dtt.RemoveAll();
	Dtt.Data.RemoveAll();
}
uMatrix lLodeD::Return(){
	int i,j,cnt = 0;
	uMatrix New;
	lToken C = Dtt[0];
	C.Split('\t');
	New.Init(Dtt.GetSize(),C.GetSize());
	for(i = 0;i< Dtt.GetSize();i++){
		lToken Col = Dtt[i];
		Col.Split('\t');
		for(j = 0;j< Col.GetSize();j++){
			lString Dpixel = Col[j]; 
			New.D[cnt++] = Dpixel.F();
		}
	}
	New.Temp();
	return New;
}

void lLodeD::Return2(){
	int i,j,cnt = 0;
	uMatrix New;
	lToken C = Dtt[0];
	C.Split('\t');
	New.Init(Dtt.GetSize(),C.GetSize());
	for(i = 0;i< Dtt.GetSize();i++){
		lToken Col = Dtt[i];
		Col.Split('\t');
		for(j = 0;j< Col.GetSize();j++){
			lString Dpixel = Col[j]; 
			New.D[cnt++] = Dpixel.F();
		}
	}
}