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
	uMatrix *New;
	for(i = 0;i< 4;i++){
		for(j = 0;j< 14;j++){
			char buf[100];
			sprintf(buf,"E:\\cpp\\1st_data_m3\\%d_%d_0.txt\0",i,j);
			lLodeD A = buf;
			New = new uMatrix;
			*New = A.Return();
			d_Rode.AddTail(New);
			A.RemoveAll();
		}
	}
}
void uOutlier::RemoveAll(){
	int i;
	for(i = 0;i< d_Rode.Getsize();i++){
		uMatrix *Del = (uMatrix*)d_Rode.Search(i);
		Del->RemoveAll();
		if(Del)delete(Del);
		if(d_PAA.Getsize()>0){
			Del = (uMatrix*)d_PAA.Search(i);
			Del->RemoveAll();
			if(Del)delete(Del);
		}
		if(d_Mean.Getsize()>0){
			Del = (uMatrix*)d_Mean.Search(i);
			Del->RemoveAll();
			if(Del)delete(Del);
		}
	}
	d_PAA.RemoveAll2();
	d_Rode.RemoveAll2();
	d_Mean.RemoveAll2();
}
int uOutlier::GetSize(){
	return d_Rode.Getsize();
}
uMatrix uOutlier::operator [](int n){
	uMatrix *Dt,Out;
	Dt = (uMatrix*)d_Rode.Search(n);
	Out = *Dt;
	Out.Temp();
	return Out;
}
uMatrix uOutlier::PAA(uMatrix *Dt,int n){
	uMatrix D,Paa,ColPaa;
	int i,j,old = 0,cnt = 0;
	D = *Dt;
	ColPaa.Init(1,3);
	for(i = 0;i< D.R;i++){
		if(i/(D.R/n) != old){
			ColPaa = ColPaa/cnt;
			Paa.RAdd(ColPaa);
			ColPaa.RemoveAll();
			ColPaa.Init(1,3);
			cnt = 0;
		}
		ColPaa = ColPaa+D.RowVector(i);
		cnt+=1;
		old = i/(D.R/n);
	}
	ColPaa = ColPaa/cnt;
	Paa.RAdd(ColPaa);
	ColPaa.RemoveAll();
	Paa.Temp();
	return Paa;
}
void uOutlier::PAAALL(){
	uMatrix *Paa,*Save;
	int i;
	for(i = 0;i< this->d_Rode.Getsize();i++){
		Paa = (uMatrix*)d_Rode.Search(i);
		Save = new uMatrix;
		*Save = PAA(Paa,20);
		this->d_PAA.AddTail(Save);
	}
}

uMatrix uOutlier::PAAReturn(int n){
	uMatrix *A,B;
	A = (uMatrix*)d_PAA.Search(n);
	B = *A;
	B.Temp();
	return B;
}
void uOutlier::PAASAVE(){
	uMatrix *A;
	int i,j,cnt = 0;
	for(i = 0;i< 4;i++){
		for(j = 0;j< 14;j++){
			char buf[100];
			sprintf(buf,"E:\\cpp\\1st_data_m3_PAA\\%d_%d_0.txt",i,j);
			A = (uMatrix*)d_PAA.Search(cnt++);
			A->Save(buf);
		}
	}
}
void uOutlier::ALLMean(){
	uMatrix *A;
	int i,j;
	for(i = 0;i<d_Rode.Getsize();i++){
		A = (uMatrix*)d_Rode.Search(i);
		uMatrix *Mn = new uMatrix;		
		Mn->Init(1,3);
		for(j = 0;j< A->R;j++){
			*Mn = *Mn +A->RowVector(j);
		}
		*Mn = *Mn/A->R;
		d_Mean.AddTail(Mn);
	}
}
void uOutlier::MeanSave(){
	uMatrix *A;
	int i,j,cnt = 0;
	for(i = 0;i< 4;i++){
		for(j = 0;j< 14;j++){
			char buf[100];
			sprintf(buf,"E:\\cpp\\1st_data_m3_Mean\\%d_%d_0.txt",i,j);
			A = (uMatrix*)d_Mean.Search(cnt++);
			A->Save(buf);
		}
	}
}
uMatrix uOutlier::PAAslide(int n,int winS){
	uMatrix *A,Mn,out;
	int i,j;
	A = (uMatrix*)d_Rode.Search(n);
	Mn.Init(1,3);
	for(i =0;i<A->R-winS+1;i++){
		for(j = 0;j<winS;j++){
			Mn = Mn+A->RowVector(i+j);
		}
		Mn = Mn/winS;
		out.RAdd(Mn);
		Mn = Mn*0;
	}
	out.Temp();
	return out;
}
void uOutlier::PAAALL2(){
	int i;
	for(i = 0;i<d_Rode.Getsize();i++){
		uMatrix *S = new uMatrix;
		*S = PAAslide(i,5);
		d_PAA.AddTail(S);
	}
}