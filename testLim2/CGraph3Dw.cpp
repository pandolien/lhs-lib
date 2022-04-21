#include "stdafx.h"
#include "CGraph3Dw.h"

lGraph3Dw::lGraph3Dw(){
	axis[0] = -10;
	axis[1] = 10;
	axis[2] = -10;
	axis[3] = 10;
	axis[4] = -10;
	axis[5] = 10;

}
lGraph3Dw::~lGraph3Dw(){
	RemoveAll();
}
void lGraph3Dw::Init(CWnd *p,CRect rc){
	gr.Init(p);
	gr.CreateDlg(rc);
}
void lGraph3Dw::RemoveAll(){
	D_uMat.RemoveAll2();
	D_color.RemoveAll();
}
void lGraph3Dw::Add(void *D){
	long *C = new long;
	D_uMat.AddTail(D);
	*C = RGB(0,0,0);
	D_color.AddTail(C);
}
void lGraph3Dw::Add(void *D,long Clr){
	long *C = new long;
	D_uMat.AddTail(D);
	*C = Clr;
	D_color.AddTail(C);
}
void lGraph3Dw::show(){
	uMatrix A,*DuMat;
	int i,j,cnt = 0;
	long *Color,*DC;
	for(i = 0;i < D_uMat.Getsize();i++){
		DuMat = (uMatrix*)D_uMat.Search(i);
		A.RAdd(*DuMat);
	}
	Color = new long[A.R];
	for(i = 0;i < D_color.Getsize();i++){
		DuMat = (uMatrix*)D_uMat.Search(i);
		DC = (long*)D_color.Search(i);
		for(j = 0;j<DuMat->R;j++)	Color[cnt++] = *DC;
	}
	gr.PCloud(A.D,A.R,Color);
	gr.Axis(axis);
	gr.Redraw();
	delete[](Color);
}	
void lGraph3Dw::Axis(float *d){
	memmove(axis,d,sizeof(float)*6);
}