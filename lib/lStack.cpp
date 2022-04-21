#include "stdafx.h"
#include "lStack.h"
lStack::lStack(){
	nTail = NULL;
	Init();
}
lStack::lStack(void *D){
	nTail = NULL;
	Init(D);
}
lStack::lStack(BOOL T){
	nTail = NULL;
	Init(T);
}
lStack::~lStack(){
	RemoveAll();
}
void lStack::Init(){
	RemoveAll();
	nTail = NULL;
	temp = FALSE;
	n = 0;
}
void lStack::Init(void *D){
	RemoveAll();
	StNode *New = new StNode;
	New->nPrev = NULL;
	New->D = D;
	nTail = New;
	temp = FALSE;
	n = 1;
}
void lStack::Init(BOOL T){
	RemoveAll();
	nTail = NULL;
	temp = T;
	n = 0;
}
void lStack::RemoveAll(){
	if(nTail == NULL) return;
	StNode *Tep,*nFind;
	nFind = nTail;
	nTail = NULL;
	while(1){
		Tep = nFind->nPrev;
		nFind->nPrev = NULL;
		if(temp == FALSE){
			if(nFind->D) delete(nFind->D);
		}
		if(nFind)delete(nFind);
		nFind = Tep;
		if(Tep == NULL) break;
	}

}
void* lStack::pop(){
	if(nTail == NULL) return NULL;
	void *RD;
	StNode *Tep = nTail->nPrev;
	nTail->nPrev = NULL;
	RD = nTail->D;
	nTail->D = NULL;
	delete(nTail);
	nTail = Tep;
	return RD;
}

void lStack::push(void*D){
	StNode *New = new StNode;
	if(nTail)	New->nPrev = nTail;
	else		New->nPrev = NULL;
	New->D = D;
	nTail = New;
}