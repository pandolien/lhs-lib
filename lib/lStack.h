#ifndef __LSTACK_H__
#define __LSTACK_H__
typedef struct _StackNode{
	_StackNode *nPrev;
	void *D;
}StNode;
class lStack{
public:
	lStack();
	lStack(void *D);
	lStack(BOOL T);
	~lStack();
public:
	StNode *nTail;
	int n;
	BOOL temp;
public:
	void Init();
	void Init(BOOL T);
	void Init(void *D);
	void RemoveAll();
	void *pop();
	void push(void *D);
};
#endif;