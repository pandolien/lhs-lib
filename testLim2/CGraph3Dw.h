#ifndef __CGRAPH3DW_H__
#define __CGRAPH3DW_H__
#include "Graph3D.dll/Graph3Dw.h"
#include "lPRTList.h"
#include "uMatrix.h"
class lGraph3Dw{
public:
	lGraph3Dw();
	~lGraph3Dw();
public:
	lPRTList D_uMat;
	lPRTList D_color;
	CGraph3Dw gr;
	float axis[6];
public:
	void Init(CWnd *,CRect);
	void RemoveAll();
	void Add(void *);
	void Add(void *,long);
	void show();
	void Axis(float *d);
};
#endif;