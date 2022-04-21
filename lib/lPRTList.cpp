#include "stdafx.h"
#include "lPRTList.h"
lPRTList::lPRTList(){
	Init();
}
lPRTList::~lPRTList(){
	RemoveAll();
}
void lPRTList::Init(){
	nHead = NULL;
	nTail = NULL;
	nFind = NULL;
	n = 0;
	this->CurrentLocation = -1;
}
void lPRTList::RemoveAll(){
	if(nHead == NULL &&nTail == NULL)return;
	LNode *Tep;
	nFind = nHead;
	while(1){
		if(nFind)Tep = nFind->nNext;
		else Tep = NULL;
		if(nFind)nFind->nNext = NULL;
		if(nFind->D) delete(nFind->D);
		nFind->D = NULL;
		delete(nFind);
		nFind = Tep;
		if(Tep == NULL) break;
	}
	n = 0;
	this->CurrentLocation = -1;
	nHead = NULL;
	nTail = NULL;
	nFind = NULL;
}
void lPRTList::RemoveAll2(){
	if(nHead == NULL &&nTail == NULL)return;
	LNode *Tep;
	nFind = nHead;
	while(1){
		if(nFind)Tep = nFind->nNext;
		else Tep = NULL;
		if(nFind) nFind->nNext = NULL;
		nFind->D = NULL;
		delete(nFind);
		nFind = Tep;
		if(Tep == NULL) break;
	}
	n = 0;
	this->CurrentLocation = -1;
	
	nHead = NULL;
	nTail = NULL;
	nFind = NULL;
}
void lPRTList::AddHead(void *D){
	LNode *New = new LNode;
	New->nNext	=	NULL;
	New->nPrev	=	NULL;
	New->D		=	D;
	if(nHead){
		nHead->nPrev	= New;
		New->nNext		= nHead;
		nHead			= New;
	}
	else nHead			= New;
	if(nTail == NULL) nTail = New;
	n +=1;
}
void lPRTList::AddTail(void *D){
	LNode *New = new LNode;
	New->nNext = NULL;
	New->nPrev = NULL;
	New->D = D;
	if(nTail){
		nTail->nNext = New;
		New->nPrev = nTail;
		nTail = New;
	}
	else nTail = New;
	if(nHead == NULL) nHead = New;
	n +=1;
}
void* lPRTList::Find(int num){
	int cnt = 0;
	nFind = nHead;
	this->CurrentLocation = 0;
	if(num == 0) return nHead->D;
	while(1){
		nFind = nFind->nNext;
		cnt++;
		if(nFind == NULL) return NULL;
		if(cnt == num) break;
		
	}
	this->CurrentLocation = cnt;
	return nFind->D;
}
void *lPRTList::Search(int num){
	if(num <0) return NULL;
	if(num == 0) return Find(num);
	if(n <= num) return NULL;
	
	if(CurrentLocation == num)return nFind->D;
	else if(CurrentLocation-1 == num){
		if(nFind->nPrev == NULL) return NULL;
		nFind = nFind->nPrev;
		CurrentLocation -=1;
		return nFind->D;
	}
	else if(CurrentLocation+1 == num){
		if(nFind->nNext == NULL) return NULL;
		nFind=nFind->nNext;
		CurrentLocation+=1;
		return nFind->D;
	}
	else{
		return Find(num);
	}
}
void lPRTList::DeleteTail(){
	if(nTail == NULL) return;
	if(nTail->nPrev == NULL) nHead = NULL;
	LNode *T = nTail->nPrev;
	if(T)T->nNext = NULL;
	nTail->nPrev = NULL;
	nTail->nNext = NULL;
	if(nTail->D)delete(nTail->D);
	nTail->D = NULL;
	if(nTail) delete(nTail);
	nTail = T;
	n-=1;
}
void lPRTList::DeleteTail2(){
	if(nTail == NULL) return;
	if(nTail->nPrev == NULL) nHead = NULL;
	LNode *T = nTail->nPrev;
	if(T)T->nNext = NULL;
	nTail->nPrev = NULL;
	nTail->nNext = NULL;
	nTail->D = NULL;
	if(nTail) delete(nTail);
	nTail = T;
	n-=1;
}
void lPRTList::DeleteHead(){
	if(nHead == NULL) return;
	if(nHead->nNext == NULL) nTail = NULL;
	LNode *T = nHead->nNext;
	if(T)T->nPrev = NULL;
	nHead->nNext = NULL;
	nHead->nPrev = NULL;
	if(nHead->D) delete(nHead->D);
	nHead->D = NULL;
	if(nHead) delete(nHead);
	nHead = T;
	n-=1;
}

void lPRTList::DeleteHead2(){
	if(nHead == NULL) return;
	if(nHead->nNext == NULL) nTail = NULL;
	LNode *T = nHead->nNext;
	if(T)T->nPrev = NULL;
	nHead->nNext = NULL;
	nHead->nPrev = NULL;
	nHead->D = NULL;
	if(nHead) delete(nHead);
	nHead = T;
	n-=1;
}
int lPRTList::Getsize(){
	return n;
}
