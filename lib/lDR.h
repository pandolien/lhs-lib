// lDR.h: interface for the lDR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LDR_H__08E80A7F_81A6_4201_8F8F_3A1DC76BD921__INCLUDED_)
#define AFX_LDR_H__08E80A7F_81A6_4201_8F8F_3A1DC76BD921__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "uMatrix.h"
#include "lDistance.h"
/*
	**lDR is a dimensionality reduction library file
	**In Data File is a 
			Dimension
			->
		*	*	*
		*	*	*	|
		*	*	*	|	number of data
		*	*	*	v
		*	*	*
	////////////////////////////////////////////////LHS
*/
typedef float (lDistance::*Dis)(uMatrix &,uMatrix &);
class lDR  
{
public:
	lDR();
	virtual ~lDR();
public:
	uMatrix PCA(uMatrix &,int);
	uMatrix t_SNE(uMatrix&,int,Dis Func);
	public://t-sne code
		void tsneRMatrix(uMatrix &,int,int);
		float p(uMatrix &,int);
		float q(uMatrix &,int);
		float Var(uMatrix &A);
};

#endif // !defined(AFX_LDR_H__08E80A7F_81A6_4201_8F8F_3A1DC76BD921__INCLUDED_)
