#include "stdafx.h"
#include "lQueue.h"
lQueue::lQueue(){
	this->nHead = NULL;
	this->nTail = NULL;
	this->temp	= FALSE;
	this->LC	= TRUE;
	num = 0;
}
lQueue::~lQueue(){
	this->RemoveAll();
}
void lQueue::Init(){
	this->RemoveAll();
	this->nHead = NULL;
	this->nTail = NULL;
	this->temp	= FALSE;
	this->LC	= TRUE;
	num = 0;
}
void lQueue::RemoveAll(){
	if(nTail == NULL && nHead == NULL) return;
	QuNode *Tep,*nFind;
	nFind = nHead;
	nHead = NULL;
	nTail->nNext = NULL;
	nTail = NULL;
	num = 0;
	while(1){
		Tep = nFind->nNext;
		if(temp == FALSE){
			if(nFind->Data) delete(nFind->Data);
		}
		nFind->Data = NULL;
		nFind->nNext = NULL;
		delete(nFind);
		nFind = Tep;
		if(Tep == NULL) break;
	}
}
void lQueue::LineSet(){
	LC = TRUE;
}
void lQueue::CircleSet(){
	LC = FALSE;
}
void lQueue::Add(void *D){
	QuNode *New= new QuNode;
	New->nNext= NULL;
	New->Data = D;
	if(nHead == NULL) nHead = New;
	if(nTail == NULL) nTail = New;
	else{
		nTail->nNext = New;
		nTail = New;
		if(LC == FALSE) New->nNext = nHead;
	}
	num+=1;
}
void lQueue::remove(){
	QuNode *Tep;
	Tep = nHead->nNext;
	if(temp == FALSE){
		if(nHead->Data)
			delete(nHead->Data);
	}
	nHead->Data =NULL;
	if(nHead)delete(nHead);
	nHead = Tep;
	if(nHead == NULL) nTail = NULL;
}
void *lQueue::peek(){
	return nHead->Data;
}
int lQueue::isEmpty(){
	return num;	
}
int lQueue::GetSize(){
	return num;
}
