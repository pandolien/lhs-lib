#include "stdafx.h"
#include "lHeap.h"
#include "lPRTList.h"
lHeap::lHeap(){
}
lHeap::~lHeap(){
}
void lHeap::Add(float Key,void *D){
	HNode *New = new HNode;
	New->D = D;
	New->Key = Key;
	Node.AddTail(New);
}
void lHeap::RemoveAll(){
	int i;
	for(i =0;i<Node.Getsize();i++){
		HNode *De = (HNode*)Node.Search(i);
		De->D = NULL;
		De->Key = 0;
		if(De) delete(De);
	}
	Node.RemoveAll2();
}
void lHeap::Change(int n1,int n2){
	void *Tep;
	Node.Search(n1);
	LNode *N1 = Node.nFind;
	Node.Search(n2);
	LNode *N2 = Node.nFind;
	Tep = N1->D;
	N1->D = N2->D;
	N2->D = Tep;
}
void lHeap::HeapMax(){
	int i,root,c;
	for(i = 1;i< Node.Getsize();i++){
		c = i;
		while(1){
			root = (c-1)/2;
			HNode *Root = (HNode*)Node.Search(root);
			HNode *ND = (HNode*)Node.Search(c);
			if(Root->Key <= ND->Key) Change(c,root);
			else break;
			c = root;
			if(c == 0) break;
		}
	}
}
void lHeap::HeapMin(){
	int i,root,c;
	for(i = 1;i< Node.Getsize();i++){
		c = i;
		while(1){
			root = (c-1)/2;
			HNode *Root = (HNode*)Node.Search(root);
			HNode *ND = (HNode*)Node.Search(c);
			if(Root->Key >= ND->Key) Change(c,root);
			else break;
			c = root;
			if(c == 0) break;
		}
	}
}
HNode* lHeap::Return(){
	if(Node.nHead == NULL) return NULL;
	HNode *Rt = (HNode*)Node.nHead->D;
	Node.DeleteHead2();
	if(Node.nTail == NULL) return Rt;
	Node.AddHead(Node.nTail->D);
	Node.DeleteTail2();
	int root = 1,N1,N2;
	while(1){
		N1 = root*2;
		N2 = root*2+1;
		if(Node.Getsize()<N1||Node.Getsize()<N2) break;
		HNode *Root = (HNode*)Node.Search(root-1); 
		HNode *N1D = (HNode*)Node.Search(N1-1);
		HNode *N2D = (HNode*)Node.Search(N2-1);
		if(N2D == NULL){
			if(N1D->Key > Root->Key) this->Change(N1-1,root-1);
			break;
		}
		else{
			if(N1D->Key >= N2D->Key){
				if(N1D->Key >= Root->Key){
					Change(N1-1,root-1);
					root = N1;
				}
				else break;
			}
			else{
				if(N2D->Key >= Root->Key){
					Change(N2-1,root-1);
					root = N2;
				}
				else break;
			}
					
		}
	}
	return Rt;
}
HNode* lHeap::operator[](int n){
	HNode *Rt = (HNode*)Node.Search(n);
	return Rt;
}