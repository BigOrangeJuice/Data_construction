#include <iostream>
using namespace std;
#include <malloc.h>

#define maxsize 100

typedef struct SqStack{
	int *base;
	int stacksize;
}SqStack;

void Init(SqStack &S);//��ʼ�� 
bool IsEmpty(SqStack &S);//�жϿ� 
bool IsFull(SqStack &S);//�ж��� 
int Length(SqStack &S);//���س��� 
void Push(SqStack &S,int data);//��ջ 
int Pop(SqStack &S);//��ջ������Ԫ�� 
int GetHead(SqStack &S);//��ȡջ��Ԫ�� 
void Clear(SqStack &S);//��� 
void Traverse(SqStack &S);//���� 

void Init(SqStack &S){
	S.base = (int*)malloc(sizeof(int)*maxsize);
	S.stacksize = 0;
}

bool IsEmpty(SqStack &S){
	return S.stacksize == 0;
}

bool IsFull(SqStack &S){
	return S.stacksize == maxsize; 
}

int Length(SqStack &S){
	return S.stacksize;
}

void Push(SqStack &S,int data){
	if(IsFull(S)){
		cout<<"��"<<endl;
		return;
	}
	S.base[S.stacksize++] = data;
}

int Pop(SqStack &S){
	if(IsEmpty(S)){
		cout<<"��"<<endl;
		return -1; 
	}
	return S.base[--S.stacksize];
}

int GetHead(SqStack &S){
	if(IsEmpty(S)){
		cout<<"��"<<endl;
		return -1; 
	}
	return S.base[S.stacksize-1];
}

void Clear(SqStack &S){
	S.stacksize = 0;
}

void Traverse(SqStack &S){
	if(IsEmpty(S)){
		cout<<"��"<<endl;
		return; 
	}
	for(int i=S.stacksize-1;i>=0;--i){
		cout<<S.base[i]<<endl;
	} 
}

int main(){
	SqStack S;
	Init(S);

	return 0 ;
}


