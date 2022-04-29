// lDistance.cpp: implementation of the lDistance class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "lDistance.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

lDistance::lDistance()
{

}

lDistance::~lDistance()
{

}
float lDistance::DTW(uMatrix &A,uMatrix &B){
	uMatrix dtw;
	int i,j;
	dtw.Init(MAX(A.C,A.R)+1,MAX(B.C,B.R)+1);
	for(i = 1;i< dtw.R;i++){
		for(j = 1;j<dtw.C;j++){
			float min = MIN(dtw.DOUT(i-1,j),dtw.DOUT(i,j-1));
			min = MIN(dtw.DOUT(i-1,j-1),min);
			float dis = ABS(A.D[i]-B.D[j]);
			dtw.DIN(i,j,dis*dis+min);
		}
	}
	if(A.isTemp()){A.RemoveTemp();}
	if(B.isTemp()){B.RemoveTemp();}
	return (float)(sqrt(dtw.DOUT(dtw.R-1,dtw.C-1)));
}
float lDistance::Euclidean(uMatrix &A,uMatrix &B){
	int i;
	float Dis= 0.0;
	if(MAX(A.R,A.C) != MAX(B.R,B.C)) return 0.0;
	for(i = 0;i< MAX(A.R,A.C);i++)	Dis = A.D[i]*A.D[i]+B.D[i]*B.D[i];
	if(A.isTemp()){A.RemoveTemp();}
	if(B.isTemp()){B.RemoveTemp();}
	return (float)(sqrt(Dis));
}
float lDistance::Hamming(uMatrix &A,uMatrix &B){
	int i;
	float Dis = 0.0;
	if(MAX(A.R,A.C) != MAX(B.R,B.C)) return 0.0;
	for(i = 0;i< MAX(A.R,A.C);i++)Dis +=ABS(A.D[i]-B.D[i]);
	return Dis;
}
float lDistance::Manhattan(uMatrix &A,uMatrix &B){
	int i;
	float Dis = 0.0;
	if(MAX(A.R,A.C) != MAX(B.R,B.C)) return 0.0;
	for(i = 0;i< MAX(A.R,A.C);i++){
		if(A.D[i] != B.D[i])Dis +=1;
	}
	return Dis;
}
