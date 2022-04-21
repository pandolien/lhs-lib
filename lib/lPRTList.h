#ifndef __LPRTLIST_H__
#define __LPRTLIST_H__
typedef struct ListNode{
	ListNode *nPrev;
	ListNode *nNext;
	void *D;
}LNode;
class lPRTList{
public:
	lPRTList();
	~lPRTList();
public:
	LNode *nHead;
	LNode *nTail;
	LNode *nFind;
	int n;
	int CurrentLocation;
public:
	void Init();
	void RemoveAll();
	void RemoveAll2();
public:
	void AddHead(void *D);
	void AddTail(void *D);
	void* Find(int num);
	void* Search(int num);
public:
	void DeleteTail();
	void DeleteTail2();
	void DeleteHead();
	void DeleteHead2();
	void DeleteNum(int n);
public:
	int Getsize();
};
#endif;