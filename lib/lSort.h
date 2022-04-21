#ifndef __LSORT_H__
#define __LSORT_H__
#include "lPRTList.h"
typedef struct SortNode{
	float Key;
	void *Data;
}SNode;
class lSort{
public:
	lSort();
	~lSort();
public:
	lPRTList Node;
public:
	void RemoveAll();
	void Add(float Key,void *Data);
	void Selection();
	void Insertion();
	void Bubble();
	void Merge();
	SNode* MergeIn(SNode *N,int n);
	void Quick();
	SNode* QuickIn(SNode *N,int n);
	int	QuickMinLen(SNode *N,int n);
	int	QuickMaxLen(SNode *N,int n);
	SNode* QuickDivisionMin(SNode *N,int n);
	SNode* QuickDivisionMax(SNode *N,int n);
public:
	float operator [](int n);
};
#endif;