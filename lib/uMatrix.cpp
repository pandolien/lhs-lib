// uMatrix1.cpp: implementation of the uMatrix class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UMatrix.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

uMatrix::uMatrix()
{
	D = NULL;
	R = 0;
	C = 0;
	NoTemp();
}
uMatrix::uMatrix(int r,int c)
{
	D = NULL;
	Init(r,c);
	NoTemp();
}
uMatrix::uMatrix(uMatrix &other)
{
	D = NULL;
	R = 0;
	C = 0;
	Init(other.R,other.C);
	memmove(D,other.D,sizeof(float)*R*C);
	if(other.isTemp())other.RemoveTemp();
}

uMatrix::~uMatrix()
{
	if(this->isTemp()){ return;}
	RemoveAll();
}
void uMatrix::Init(int r, int c){
	RemoveAll();
	R = r;
	C = c;
	D = new float[R*C];
	int i;
	for(i = 0;i< R*C;i++)	D[i] = 0;
	NoTemp();
}
void uMatrix::RemoveAll(){
	if(D)delete(D);
	D = NULL;
	R = 0;
	C = 0;
}
uMatrix uMatrix::operator *(uMatrix &other){
	uMatrix New;
	int i,j,k;
	float SUM = 0.0;
	New.Temp();
	if(C != other.R ||this->SizeConfirm()||other.SizeConfirm()) return New;
	New.Init(R,other.C);
	for(i =0;i< New.R;i++){
		for(j = 0;j< New.C;j++){
			SUM = 0.0;
			for(k = 0;k < C;k++){
				SUM+= (D[i*C+k]*other.D[k*other.C+j]);
			}
			New.D[i*New.C+j] = SUM;
		}		
	}
	if(other.isTemp()) other.RemoveTemp();
	return New;
}

uMatrix uMatrix::operator *(int other){
	uMatrix New = uMatrix(R,C);
	int i;
	New.Temp();
	memmove(New.D,D,sizeof(float)*R*C);
	for(i = 0;i< R*C;i++){
		New.D[i] *= (float)(other);
	}
	return New;
}
uMatrix uMatrix::operator *(float other){
	uMatrix New = uMatrix(R,C);
	int i;
	New.Temp();
	memmove(New.D,D,sizeof(float)*R*C);
	for(i = 0;i< R*C;i++){
		New.D[i] *= other;
	}
	return New;
}

uMatrix uMatrix::operator /(int other){
	uMatrix New = uMatrix(R,C);
	int i;
	New.Init(R,C);
	New.Temp();
	memmove(New.D,D,sizeof(float)*R*C);
	for(i = 0;i< R*C;i++){
		New.D[i] /= (float)(other);
	}
	return New;
}
uMatrix uMatrix::operator /(float other){
	uMatrix New = uMatrix(R,C);
	int i;
	New.Init(R,C);
	New.Temp();
	memmove(New.D,D,sizeof(float)*R*C);
	for(i = 0;i< R*C;i++){
		New.D[i] /= other;
	}
	return New;
}
uMatrix uMatrix::operator +(uMatrix &other){
	uMatrix New;
	if(other.SizeConfirm()||SizeConfirm()) return New;
	New.Init(R,C);
	memmove(New.D,D,sizeof(float)*R*C);
	int i;
	memmove(New.D,D,sizeof(float)*R*C);
	New.Temp();
	for(i = 0;i< R*C;i++){
		New.D[i] += other.D[i];
	}
	if(other.isTemp()) other.RemoveTemp();
	return New;
}
uMatrix uMatrix::operator -(uMatrix &other){
	uMatrix New = uMatrix(R,C);
	int i;
	if(other.SizeConfirm()||SizeConfirm()) return New;
	New.Init(R,C);
	memmove(New.D,D,sizeof(float)*R*C);
	New.Temp();
	for(i = 0;i< R*C;i++){
		New.D[i] -= other.D[i];
	}
	if(other.isTemp()) other.RemoveTemp();
	return New;
}
void uMatrix::operator =(uMatrix &other){
	RemoveAll();
	Init(other.R,other.C);
	memmove(D,other.D,sizeof(float)*R*C);
	if(other.isTemp()) other.RemoveTemp();
}
void uMatrix::Transform(){
	int cnt = 0;
	uMatrix Tep;
	Tep = T();
	R = Tep.R;
	C = Tep.C;
	memmove(D,Tep.D,sizeof(float)*R*C);
}
uMatrix uMatrix::T(){
	int i,j,cnt = 0;
	uMatrix Tep;
	Tep.Init(C,R);
	Tep.Temp();
	for(i = 0;i< Tep.C;i++){
		for(j = 0;j< Tep.R;j++){
			Tep.D[j*Tep.C+i] = D[cnt++]; 
		}
	}
	return Tep;
}

#include <math.h>
uMatrix uMatrix::randomUnit(int n){
	int i;
	float sum = 0.0;
	uMatrix Unit;
	Unit.Init(1,n);
	for(i = 0;i< n;i++)
		Unit.D[i] = Rand()*2-1;
	Unit = Unit/Norm(Unit);
	Unit.Temp();
	return Unit;
	
}
void uMatrix::SVD(uMatrix &U,uMatrix &S,uMatrix &V){
	uMatrix A,matrixFor1D;
	uMatrix Vt, Ut, v,u;
	A.Init(R,C);
	int i,j,k;
	memmove(A.D,D,sizeof(float)*R*C);
	k = MIN(R,C);
	for(i = 0;i< k;i++){
		if(S.D == NULL)
			matrixFor1D = A;
		else
			matrixFor1D = A.SVDA(U,S,V);
		if(A.R > A.C){
			v = SVD_1d(matrixFor1D);
			u = A*v;
			S.FAdd(Norm(u));
			u = u/Norm(u);
		}
		else{
			u = SVD_1d(matrixFor1D);
			v = A.T()*u;
			float vN = Norm(v);
			S.FAdd(vN);
			v = v/Norm(v);
		}
		U.CAdd(u);
		V.CAdd(v);
	}
	V.Transform();
}
uMatrix uMatrix::SVD_1d(uMatrix &A){
	uMatrix B,currentV,lastV,C;
	if(A.R > A.C) {B = A.T()*A;}
	else{ B = A*A.T();}
	currentV = randomUnit(MIN(A.R,A.C));
	currentV.Transform();
	while(1){
		lastV = currentV;
		currentV = B*lastV;
		currentV = currentV/Norm(currentV);
		C = currentV.T()*lastV;
		if(ABS(C.D[0]) >= 1.0- 0.001){
			if(A.isTemp())A.RemoveTemp();
			currentV.Temp();
			return currentV;
		}
	}
	if(A.isTemp())A.RemoveTemp();
	currentV.Temp();
	return currentV;
}
float uMatrix::sum(uMatrix &A){
	float sum = 0.0;
	int i;
	for(i = 0;i< A.C*A.R;i++){
		sum +=A.D[i];
	}
	if(A.isTemp())A.RemoveTemp();
	return sum;
}
float uMatrix::Norm(uMatrix &A){
	int i;
	float N = 0.0;
	for(i = 0;i< A.C*A.R;i++){
		N += A.D[i]*A.D[i];
	}
	if(A.isTemp())A.RemoveTemp();
	return sqrt(N);
}
uMatrix uMatrix::outer(uMatrix &A,uMatrix &B){// input Data A in data R  = 1 C = n,Data B in data(R  = 1 C = n)
	uMatrix Out;
	int i,j,cnt = 0;
	Out.Init(A.C,B.C);
	Out.Temp();
	for(i = 0;i< Out.R;i++){
		for(j = 0;j< Out.C;j++){
			Out.D[cnt++] = A.D[i]*B.D[j];
		}
	}
	if(A.isTemp())A.RemoveTemp();
	if(B.isTemp())B.RemoveTemp();
	return Out;
}
uMatrix uMatrix::RowVector(int n){
	uMatrix Out;
	Out.Init(1,C);
	int i;
	for(i = 0;i< C;i++){
		Out.D[i] = D[n*C+i];
	}
	Out.Temp();
	return Out;
}
uMatrix uMatrix::ColVector(int n){
	uMatrix Out;
	int i;
	Out.Init(R,1);
	for(i = 0;i< R;i++){
		Out.D[i] = D[i*C+n];
	}
	Out.Temp();
	return Out;
}
void uMatrix::CAdd(uMatrix &A){
	if(D == NULL){
		Init(A.R,A.C);
		memmove(D,A.D,sizeof(float)*R*C);
		if(A.isTemp())A.RemoveTemp();
		return;
	}
	if(R != A.R) {
		if(A.isTemp())A.RemoveTemp();
		return;
	}
	uMatrix Tep = uMatrix(R,C+A.C);
	int i,j,n;
	for(i = 0;i< R;i++){
		for(j=0;j< C;j++){
			Tep.D[i*Tep.C+j] = D[i*C+j];
		}
		for(j = 0;j< A.C;j++){
			n = i*Tep.C+C+j;
			Tep.D[n] = A.D[i*A.C+j];
		}
	}
	RemoveAll();
	Init(Tep.R,Tep.C);
	memmove(D,Tep.D,sizeof(float)*R*C);
	int CC = R*C;
	for(i = 0;i< CC;i++){
		D[i] = D[i];
	}
	if(A.isTemp())A.RemoveTemp();
}
void uMatrix::RAdd(uMatrix &A){
	if(D == NULL){
		Init(A.R,A.C);
		memmove(D,A.D,sizeof(float)*R*C);
		if(A.isTemp())A.RemoveTemp();
		return;
	}
	if(C != A.C) {
		if(A.isTemp())A.RemoveTemp();
		return;
	}
	uMatrix Tep = uMatrix(R+A.R,C);
	int i,j;
	for(i =0;i < Tep.R;i++){
		for(j = 0;j< Tep.C;j++){
			if(i < R){	
				Tep.D[i*C+j] = D[i*C+j];
			}
			else{ 
				Tep.D[i*C+j] = A.D[(R-i)*C+j];
			}
		}
	}
	Init(Tep.R,Tep.C);
	memmove(D,Tep.D,sizeof(float)*R*C);
	if(A.isTemp())A.RemoveTemp();
}
void uMatrix::FAdd(float A){
	if(D == NULL){
		Init(1,1);
		D[0] = A;
		return;
	}
	uMatrix Tep;
	Tep.Init(R,C+1);
	memmove(&Tep.D[0],D,sizeof(float)*C);
	memmove(&Tep.D[C],&A,sizeof(float));
	Init(Tep.R,Tep.C);
	memmove(D,Tep.D,sizeof(float)*Tep.C);
	for(int i = 0;i< Tep.C;i++){
		D[i] = D[i];
	}
}
uMatrix uMatrix::SVDA(uMatrix &U,uMatrix &S,uMatrix &V){
	uMatrix A = uMatrix(R,C);
	uMatrix Ut,Vt,ou;
	int i;
	memmove(A.D,D,sizeof(float)*R*C);
	for(i = 0;i< S.C;i++){
		Ut = U.ColVector(i);
		Vt = V.ColVector(i);
		ou = this->outer(Ut.T(),Vt.T());
		ou = ou *S.D[i];
		A = A-ou;
	}
	A.Temp();
	return A; 
}
void uMatrix::diag(){
	float *Tep;
	int i;
	Tep = new float[R*C];
	memmove(Tep,D,sizeof(float)R*C);
	Init(R*C,R*C);
	for(i = 0;i< R;i++){
		D[i*R+i]=Tep[i];
	}
	delete(Tep);
}
uMatrix uMatrix::diag(uMatrix &A){
	uMatrix New;
	int i;
	New.Init(A.R*A.C,A.R*A.C);
	for(i = 0;i< New.R;i++){
		New.D[i*New.R+i] = A.D[i];
	}
	New.Temp();
	return New;
}
uMatrix uMatrix::pinv(){
	uMatrix INV,U,S,VT;
	int i;
	SVD(U,S,VT);
	U.Transform();
	VT.Transform();
	S.diag();
	for(i = 0;i< S.R;i++)
		S.D[i*S.C+i] = 1/S.D[i*S.C+i];
	INV = VT*S*U;
	INV.Temp();
	return INV;
}
void uMatrix::Save(char *D){
	lString A;
	int i,j;
	char buf[100];
	for(i = 0;i< R;i++){
		for(j = 0;j< C;j++){
			sprintf(buf,"%f\0",this->D[i*C+j]);
			A = A+buf;
			if(j<C-1) A = A+'\t';
		}
		A = A+'\n';
	}
	A.Save(D);
}
BOOL uMatrix::SizeConfirm(){
	if(C == 0||R == 0) return TRUE;
	return FALSE;
}
void uMatrix::DIN(int i,int j,float Dt){
	D[i*C+j] = Dt;
}
float uMatrix::DOUT(int i,int j){
	return D[i*C+j];
}
void uMatrix::sq(int n){
	int i;
	for(i = 0;i<R*C;i++){
		D[i] = pow(D[i],n);
	}
}