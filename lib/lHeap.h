#ifndef __LHEAP_H__
#define __LHEAP_H__
#include "lPRTList.h"
typedef struct {
	float Key;
	void *D;
}HNode;
class lHeap{
public:
	lHeap();
	~lHeap();
public:
	lPRTList Node;
public:
	void RemoveAll();
	void Add(float Key,void *D);
	void Change(int n1,int n2);
	void HeapMax();
	void HeapMin();
	HNode* Return();
	HNode* operator[](int n);
};
#endif;