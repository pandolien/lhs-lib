#ifndef __LSTRING_H__
#define __LSTRING_H__

class lString{
public:
	lString();
	lString(lString &D);
	lString(UINT D);
	lString(char *D);
	lString(char D);
	~lString();
public:
	char *Data;
	int n;
	BOOL temp;
public:
	void Init();
	void Init(lString &D);
	void Init(char *D);
	void Init(char D);
	void Init(int num);
	void RemoveAll();
public:
	BOOL isTemp(){return temp;}
	void NoTemp(){temp = FALSE;}
	void Temp(){temp = TRUE;}
	void DeleteTemp();
public:
	void operator =(lString &D);
	void operator =(char *D);
	void operator =(char D);
	lString operator +(lString &D);
	lString operator +(char *D);
	lString operator +(char D);
	lString operator *(int n);
	BOOL operator ==(lString &D);
	BOOL operator ==(char *D);
	BOOL operator ==(char D);
	BOOL compare(lString &D);
	BOOL compare(char *D);
	BOOL compare(char D);
	char operator [](int n);
public:
	void remove(char nChar);
	int Getsize();
public:
	void open(char *D);
	void Save(char *D);
public:
	float F();
	int I();
};
#endif;