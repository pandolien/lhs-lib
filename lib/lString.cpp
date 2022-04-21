#include "stdafx.h"
#include "lString.h"
lString::lString(){
	Data = NULL;
	n = 0;
}
lString::lString(lString &D){
	Data = NULL;
	n = 0;
	Init(D);
}
lString::lString(char *D){
	Data = NULL;
	n = 0;
	Init(D);
}
lString::lString(char D){
	Data = NULL;
	n = 0;
	Init(D);
}
lString::~lString(){
	if(temp) return;
	RemoveAll();
}
void lString::Init(int num){
	RemoveAll();
	Data = new char[num+1];
	Data[num] = NULL;
	n = num;
	NoTemp();
}
void lString::Init(lString &D){
	RemoveAll();
	Init(D.Data);
	D.DeleteTemp();
	NoTemp();
}
void lString::Init(char *D){
	RemoveAll();
	n = strlen(D);
	Data = new char[n+1];
	memmove(Data,D,sizeof(char)*n);
	Data[n] = NULL;
	NoTemp();
}
void lString::Init(char D){
	RemoveAll();
	n = 2;
	Data = new char[n];
	Data[0] = D;
	Data[1] = NULL;
	NoTemp();
}
void lString::RemoveAll(){
	if(Data) delete(Data);
	Data = NULL;
	n = 0;
}
void lString::DeleteTemp(){
	if(temp){RemoveAll();}
}

lString lString::operator +(lString &D){
	lString New;
	New.Temp();
	New.Init(n+D.n);
	memmove(&New.Data[0],Data,sizeof(char)*n);
	memmove(&New.Data[n],D.Data,sizeof(char)*D.n);
	New.Data[New.n] = NULL;
	D.DeleteTemp();
	return New;
}
lString lString::operator +(char *D){
	int num = strlen(D);
	lString New;
	New.Temp();
	New.Init(n+num);
	memmove(&New.Data[0],Data,sizeof(char)*n);
	memmove(&New.Data[n],D,sizeof(char)*num);
	New.Data[New.n] = NULL;
	return New;
}
lString lString::operator +(char D){
	lString New;
	New.Temp();
	New.Init(n+2);
	memmove(&New.Data[0],Data,sizeof(char)*n);
	memmove(&New.Data[n],&D,sizeof(char));
	New.Data[n+1] = NULL;
	return New;
}
void lString::operator =(lString &D){
	Init(D);
	D.DeleteTemp();
}
void lString::operator =(char *D){
	Init(D);
}
void lString::operator =(char D){
	Init(D);
}
BOOL lString::operator ==(lString &D){
	return compare(D);
}
BOOL lString::operator ==(char *D){
	return compare(D);
}
BOOL lString::operator ==(char D){
	return compare(D);
}
BOOL lString::compare(lString &D){
	BOOL Rt = compare(D.Data);
	D.DeleteTemp();
	return Rt;
}
BOOL lString::compare(char *D){
	int num = strlen(D),i = 0,j = 0,cnt =0;
	if(num == 1) return compare(D[0]);
	else if(num >= n)return FALSE;
	else{
		for(i = 0;i<= n-num;i++){
			cnt = 0;
			for(j = 0;j< num;j++){
				if(Data[i+j] == D[j])cnt +=1;
				else break;
			}
			if(cnt == num) return TRUE;
		}
	}
	return FALSE;
}
BOOL lString::compare(char D){
	int i;
	for(i = 0;i< n;i++){
		if(Data[i] == D) return TRUE;
	}
	return FALSE;
}
char lString::operator [](int n){
	return Data[n];
}
///////////////////////////////////////
void lString::remove(char nChar){
	if(Data == NULL) return;
	lString Tep;
	if(n == 1){
		if(Data[0] == nChar) RemoveAll();
		return;
	}
	else{
		int i;
		for(i = 0;i< n;i++){
			if(Data[i] == (char)nChar) continue;
			Tep = Tep+Data[i];
		}
		Init(Tep.n);
		memmove(Data,Tep.Data,sizeof(char)*Tep.n);
		Tep.RemoveAll();
	}
}
int lString::Getsize(){
	return n;
}

void lString::open(char *D){
	FILE *pfile = fopen(D,"rb");
	lString Tep;
	char ReadD[255];
	if(pfile == NULL) return;
	while(!feof(pfile)){
		fgets(ReadD,sizeof(char)*255,pfile);
		Tep = Tep+ReadD;
	}
	fclose(pfile);
	Init(Tep);
}
void lString::Save(char *D){
	FILE *pfile = fopen(D,"wb");
	fwrite(Data,1,sizeof(char)*Getsize(),pfile);
	fclose(pfile);

}
///////////////////////////////////////
#include <stdlib.h>
float lString::F(){
	return (float)atof(Data);
}
int lString::I(){
	return (int)atof(Data);
}