// uMatrix1.h: interface for the uMatrix class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _uMatrix_H_
#define _uMatrix_H_
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(x) ((x)<0 ? (-x) : (x))


#include <stdlib.h>
#include "lString.h"
#include <math.h>
class uMatrix  
{
public:
	uMatrix();
	uMatrix(int,int);
	uMatrix(uMatrix &other);
	virtual ~uMatrix();
public:
	int R,C;
	float *D;
	BOOL temp;
public://temp code;
	void Init(int,int);
	void RemoveAll();
public:
	virtual void operator =(uMatrix &other);
	virtual uMatrix operator *(uMatrix &other);
	virtual uMatrix operator *(int other);
	virtual uMatrix operator *(float other);
	virtual uMatrix operator /(int other);
	virtual uMatrix operator /(float other);
	virtual uMatrix operator +(uMatrix &other);
	virtual uMatrix operator -(uMatrix &other);
	uMatrix outer(uMatrix &A,uMatrix &B);
	void sq(int);
	void DIN(int,int,float);
	float DOUT(int,int);
public:
	BOOL isTemp(){return temp;}
	void NoTemp(){temp = FALSE;}
	void Temp(){temp = TRUE;}
	void RemoveTemp(){
		if(temp){
			RemoveAll();
			temp = FALSE;
		}
	}
public:
	float Rand(){
		return (float)(rand())/RAND_MAX;
	}
	uMatrix randomUnit(int n);
	float sum(uMatrix &A);
	float Norm(uMatrix &A);
public:
	BOOL SizeConfirm();
	///////////////////////////////
	void diag();
	uMatrix diag(uMatrix &A);
	void SVD(uMatrix &U,uMatrix &S,uMatrix &V);
	void SVD(uMatrix &U,uMatrix &S,uMatrix &V,int k);
	void SVD(uMatrix &U,uMatrix &S,uMatrix &V,float epsilon);
	void SVD(uMatrix &U,uMatrix &S,uMatrix &V,int k,float epsilon);
	uMatrix SVD_1d(uMatrix &A,float epsilon);
	uMatrix SVD_1d(uMatrix &A);
	uMatrix SVDA(uMatrix &U,uMatrix &S,uMatrix &V);
	//////////////////////////////
	void Transform();
	uMatrix T();
	uMatrix RowVector(int n);
	uMatrix ColVector(int n);
	void RAdd(uMatrix &A);
	void CAdd(uMatrix &A);
	void FAdd(float A);
	uMatrix pinv();
	void Save(char *);
};

#endif // !defined(AFX_UMATRIX1_H__59AAA3C7_6AA8_4F7A_8250_92B6553235D4__INCLUDED_)
