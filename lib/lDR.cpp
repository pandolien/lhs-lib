// lDR.cpp: implementation of the lDR class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "lDR.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

lDR::lDR()
{

}

lDR::~lDR()
{

}
uMatrix lDR::PCA(uMatrix &A,int Dim){
	uMatrix U,S,Vt,Arebuild;
	uMatrix U1,S1,Vt1;
	int i = 0;
	A.SVD(U,S,Vt);
	S.diag();
	for(i = 0;i < Dim;i++){
		U1.CAdd(U.ColVector(i));
		S1.RAdd(S.RowVector(i));
		Vt1.CAdd(Vt.ColVector(i));
	}
	Arebuild = U1*S1*Vt1;
	Arebuild.Temp();
	return Arebuild;
}
uMatrix lDR::t_SNE(uMatrix &A,int Dim,Dis Func){
	uMatrix reductionMatrix;
	tsneRMatrix(reductionMatrix,A.R,Dim);
	return reductionMatrix;
}
void lDR::tsneRMatrix(uMatrix &A,int Raw,int Col){
	int i;
	A.Init(Raw,Col);
	for(i = 0;i< Raw*Col;i++){
		A.D[i] = (float)(rand())/RAND_MAX*2-1;
	}
}
float lDR::p(uMatrix &A,int n){
	int i;
	float numerator = 0.0,denominator = 0.0;
	float S = 0;
	uMatrix Xi = A.RowVector(n);
	for(i = 0;i<A.R;i++){
		if(i == n)continue;
		uMatrix Xj = A.RowVector(i);
		uMatrix N = Xi-Xj;
		S = N.Norm(N)*N.Norm(N);
	}
	return 0.0;
}
float lDR::Var(uMatrix &A){
	int i;
	uMatrix Mn,var;
	Mn.Init(1,A.C);
	var.Init(1,A.C);
	for(i = 0;i<A.R;i++)Mn = Mn+A.RowVector(i);
	Mn = Mn/A.R;
	for(i = 0;i<A.C;i++){
		uMatrix S = A.RowVector(i)-Mn;
		S.sq(2);
		var = var + S;
		S.RemoveAll();
	}
	var = var/A.R;
	return var.Norm(var);
}