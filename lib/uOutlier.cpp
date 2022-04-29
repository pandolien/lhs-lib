// uOutlier.cpp: implementation of the uOutlier class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "testLim.h"
#include "uOutlier.h"



//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include "lLodeD.h"
#include "uMatrix.h"
#include "lDR.h"
uOutlier::uOutlier()
{
	Init();
}

uOutlier::~uOutlier()
{
	RemoveAll();
}
void uOutlier::Init(){
	int i,j;
	for(i = 0;i< 4;i++){
		for(j = 0;j< 14;j++){
			char buf[100];
			sprintf(buf,"E:\\cpp\\1st_data_m3\\%d_%d_0.txt\0",i,j);
			lLodeD A = buf;
			uMatrix *New = new uMatrix;
			*New = A.Return();
			lDR B;
			*New = B.PCA(*New,1);
			sprintf(buf,"E:\\cpp\\1st_data_m3_1D\\%d_%d_0.txt\0",i,j);
			New->Save(buf);
			dData.AddTail(New);
		}
	}
}
void uOutlier::RemoveAll(){
	RemoveList(dData);
	RemoveList(dPaa);
}
void uOutlier::RemoveList(lPRTList &D){
	int i;
	for(i = 0;i< D.Getsize();i++){
		uMatrix *N = (uMatrix*)D.Search(i);
		N->RemoveAll();
		if(N) delete(N);
	}
	D.RemoveAll2();
}
int uOutlier::GetSize(){
	return dData.Getsize();
}
uMatrix uOutlier::PAA(uMatrix *Dt,int n){
	uMatrix D,Paa,ColPaa;
	int i,j,old = 0,cnt = 0;
	D = *Dt;
	ColPaa.Init(1,D.C);
	for(i = 0;i< D.R;i++){
		if((D.R/n) < cnt){
			ColPaa = ColPaa/cnt;
			Paa.RAdd(ColPaa);
			ColPaa.RemoveAll();
			ColPaa.Init(1,D.C);
			cnt = 0;
		}
		uMatrix DR = D.RowVector(i);
		ColPaa = ColPaa+DR;
		cnt+=1;
	}
	ColPaa = ColPaa/cnt;
	Paa.RAdd(ColPaa);
	ColPaa.RemoveAll();
	Paa.Temp();
	return Paa;
}
void uOutlier::PAA_ALL(){
	int i;
	for(i = 0;i < GetSize();i++){
		uMatrix *D = (uMatrix*)dData.Search(i);
		uMatrix *DPaa = new uMatrix;
		*DPaa = PAA(D,20);
		i;
		dPaa.AddTail(DPaa);
	}
}
void uOutlier::PaaSave(){	
	int i,j,cnt = 0;
	for(i = 0;i< 4;i++){
		for(j = 0;j< 14;j++){
			uMatrix *D = (uMatrix*)dPaa.Search(cnt); 
			char buf[100];
			sprintf(buf,"E:\\cpp\\1st_data_m3_PAA\\%d_%d_0.txt\0",i,j);
			D->Save(buf);
		}
	}
	
}