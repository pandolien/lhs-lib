// lClustering.cpp: implementation of the lClustering class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "lClustering.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

lClustering::lClustering()
{
	numData = NULL;
	VtData = NULL;
}

lClustering::~lClustering()
{
	RemoveAll();
}
void lClustering::Add(lPRTList &D){
	VtData = &D;
}
void lClustering::RemoveAll(){
	if(numData) delete[](numData);
	numData = NULL;
	VtData = NULL;
}
//////////////////////////////////////////////////////////////////
uMatrix lClustering::RandUnit(int num){
	uMatrix Out;
	int i = 0;
	float S = 0.0;
	Out.Init(num,1);
	for(i = 0;i< num;i++){
		float RD = (float)(rand())/RAND_MAX*2-1;
		Out.D[i] = RD;
		S += RD*RD;
	}
	S = (float)(sqrt(S));
	Out = Out/S;
	Out.Temp();
	return Out;
}
void lClustering::RemoveList(lPRTList &D){
	int i;
	for(i = 0;i< D.Getsize();i++){
		uMatrix *Del = (uMatrix*)D.Search(i);
		Del->RemoveAll();
		delete(Del);
	}
	D.RemoveAll2();
}
void lClustering::kmAllDistance(lPRTList &RD,Dis Func){
	int i,j;
	float Old = 1e10;
	lDistance Dis; 
	for(i = 0;i<VtData->Getsize();i++){
		for(j = 0;j<RD.Getsize();j++){
			uMatrix *A = (uMatrix*)RD.Search(j);
			uMatrix *B = (uMatrix*)VtData->Search(i);
			float Dtc = (Dis.*Func)(*A,*B);
			if(Old > Dtc){
				Old = Dtc;
				numData[i] = j;
			}
		}
		Old = 1e10;
	}
}
void lClustering::kmMeanmove(lPRTList &RD){
	int i,j;
	int *cnt =new int[RD.Getsize()];
	for(i =0;i< RD.Getsize();i++){
		uMatrix *A = (uMatrix*)RD.Search(i);
		*A = *A * 0;
		cnt[i] = 0;
	}
	for(i = 0;i< VtData->Getsize();i++){
		uMatrix *B = (uMatrix*)VtData->Search(i);
		uMatrix *Sum = (uMatrix*)RD.Search(numData[i]);
		for(j  = 0;j< B->R*B->C;j++){
			Sum->D[j] += B->D[j];
		}
		cnt[numData[i]]+=1;
	}
	for(i =0;i< RD.Getsize();i++){
		uMatrix *C = (uMatrix*)RD.Search(i);
		*C = *C/cnt[i];
	}
	delete[](cnt);
}
/////////////////////////////////////////////////////////////////
void lClustering::KMeans(int k,int num,Dis Func){
	lPRTList RD;
	int i,Size = 0;
	numData = new int[VtData->Getsize()];
	for(i = 0;i< VtData->Getsize();i++){
		uMatrix *SVt = (uMatrix*)VtData->Search(i);
		Size = MAX(Size,SVt->R*SVt->C);
	}
	for(i = 0;i< k;i++){
		uMatrix *RUnit = new uMatrix;
		*RUnit = RandUnit(Size);
		RD.AddTail(RUnit);
	}
	for(i = 0;i< num;i++){
		kmAllDistance(RD,Func);
		kmMeanmove(RD);
	}
	RemoveList(RD);
}
