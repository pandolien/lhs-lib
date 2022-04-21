#ifndef __LQUEUE_H__
#define __LQUEUE_H__
typedef struct QueueNode{
	QueueNode *nNext;
	void *Data;
}QuNode;
class lQueue{
public:
	lQueue();
	~lQueue();
public:
	QuNode *nHead;
	QuNode *nTail;
	BOOL LC;
	BOOL temp;
	int num;
public:
	void Init();
	void RemoveAll();
	void LineSet();
	void CircleSet();
public:
	void Add(void *D);
	void remove();
	void* peek();
	int isEmpty();
	int GetSize();
};

#endif;