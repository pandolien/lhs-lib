#include "stdafx.h"
#include "lSort.h"
lSort::lSort(){
}
lSort::~lSort(){
	RemoveAll();
}
void lSort::Add(float Key,void *Data){
	SNode *New = new SNode;
	New->Key = Key;
	New->Data = Data;
	Node.AddTail(New);
}
void lSort::RemoveAll(){
	if(Node.Getsize() == 0)return;
	SNode *D;
	int i;
	for(i = 0;i<Node.Getsize();i++){
		D = (SNode*)Node.Search(i);
		D->Data = NULL;
		D->Key = 0;
		if(D) delete(D);
	}
	Node.RemoveAll2();
}
void lSort::Selection(){
	int i,j;
	SNode *A,*B;
	LNode *NA;
	for(i = 0;i<Node.Getsize();i++){
		Node.Search(i);
		NA = Node.nFind;
		for(j = i;j<Node.Getsize();j++){
			A = (SNode*)NA->D;
			B = (SNode*)Node.Search(j);
			if(A->Key >B->Key) {
				Node.Change(i,j);
			}
		}
	}
}
void lSort::Insertion(){
	int i,j;
	SNode *A,*B;
	LNode *NA;
	for(i = 1;i< Node.Getsize();i++){
		Node.Search(i);
		NA = Node.nFind;
		for(j = 0;j< i;j++){
			A = (SNode*)NA->D;
			B = (SNode*)Node.Search(i-j);
			if(A->Key < B->Key){
				Node.Change(i-j,i);
				break;
			}
		}
	}
}
float lSort::operator [](int n){
	SNode *N = (SNode*)Node.Search(n);
	return N->Key;
}
void lSort::Merge(){
	SNode *A = new SNode[Node.Getsize()],*S;
	int i,n = Node.Getsize();
	for(i = 0;i< n;i++)		memmove(&A[i],Node.Search(i),sizeof(SNode));
	Node.RemoveAll();
	S = MergeIn(A,n);
	delete(A);
	for(i = 0;i<n;i++){
		SNode *New = new SNode;
		memmove(New,&S[i],sizeof(SNode));
		Node.AddTail(New);
	}
	delete(S);
	S = NULL;
	A = NULL;
}

SNode* lSort::MergeIn(SNode *N,int n){
	SNode *L,*R,*A,*LS,*RS;
	int i,c1,c2,a,b;
	if(n <= 1){ 
		A = new SNode;
		memmove(A,N,sizeof(SNode));
		return A;
	}
	a = n/2; b= n-n/2;
	L = new SNode[a];
	R = new SNode[b];
	A = new SNode[n];
	memmove(L,&N[0],sizeof(SNode)*a);
	memmove(R,&N[a],sizeof(SNode)*b);
	LS = MergeIn(L,a);
	RS = MergeIn(R,b);
	delete(L);	delete(R);
	c1 = 0;c2 = 0;
	for(i = 0;i < n;i++){
		if(c1 >= a){
			memmove(&A[i],&RS[c2++],sizeof(SNode));
			continue;
		}
		if(c2 >= b){
			memmove(&A[i],&LS[c1++],sizeof(SNode));
			continue;
		}
		if(LS[c1].Key > RS[c2].Key) memmove(&A[i],&LS[c1++],sizeof(SNode));
		else memmove(&A[i],&RS[c2++],sizeof(SNode));
	}
	delete(LS);	delete(RS);
	return A;
}
void lSort::Quick(){
	SNode *A = new SNode[Node.Getsize()],*S;
	int i,n = Node.Getsize();
	for(i = 0;i< n;i++)		memmove(&A[i],Node.Search(i),sizeof(SNode));
	Node.RemoveAll();
	S = QuickIn(A,n);
	delete(A);
	for(i = 0;i<n;i++){
		SNode *New = new SNode;
		memmove(New,&S[i],sizeof(SNode));
		Node.AddTail(New);
	}
	delete(S);
	S = NULL;
	A = NULL;
}
SNode* lSort::QuickIn(SNode *N,int n){
	SNode *A,*L,*R,*LS,*RS;
	int i,c1,c2;
	if(n == 1){
		A = new SNode;
		memmove(A,N,sizeof(SNode));
		return A;
	}
	A = new SNode[n];
	c1 = this->QuickMaxLen(N,n);c2 = this->QuickMinLen(N,n);
	L = this->QuickDivisionMax(N,n);
	R = this->QuickDivisionMin(N,n);
	if(L)LS = QuickIn(L,c1);
	if(R)RS = QuickIn(R,c2);
	if(L){
		delete(L);
		memmove(&A[0],LS,sizeof(SNode)*c1);
		if(LS) delete(LS);
	}
	memmove(&A[c1],&N[0],sizeof(SNode));
	if(R){
		delete(R);	
		memmove(&A[c1+1],&RS[0],sizeof(SNode)*c2);
		if(RS)delete(RS);
	}
	return A;
}
int lSort::QuickMinLen(SNode *N,int n){
	if(n <= 1) return 0;
	int i,cnt = 0;
	for(i = 1;i<n;i++){
		if(N[0].Key >=N[i].Key)cnt+=1;
	}
	return cnt;
}
SNode* lSort::QuickDivisionMin(SNode *N,int n){
	SNode *A;
	int c = QuickMinLen(N,n),i,cnt = 0;
	if(c == 0) return NULL;
	A = new SNode[c];
	for(i = 1;i< n;i++){
		if(N[0].Key >=N[i].Key){
			memmove(&A[cnt],&N[i],sizeof(SNode));
			cnt+=1;
		}
	}
	return A;
}

int lSort::QuickMaxLen(SNode *N,int n){
	if(n <= 1) return 0;
	int i,cnt = 0;
	for(i = 1;i<n;i++){
		if(N[0].Key <N[i].Key)cnt+=1;
	}
	return cnt;
}
SNode* lSort::QuickDivisionMax(SNode *N,int n){
	SNode *A;
	int c = QuickMaxLen(N,n),i,cnt = 0;
	if(c == 0) return NULL;
	A = new SNode[c];
	for(i = 1;i< n;i++){
		if(N[0].Key <N[i].Key){
			memmove(&A[cnt],&N[i],sizeof(SNode));
			cnt+=1;
		}
	}
	return A;
}
