#include <iostream>
using namespace std;
#include <malloc.h>

#define maxsize 100

typedef struct SqStack{
	int *base;
	int stacksize;
}SqStack;

void Init(SqStack &S);//初始化 
bool IsEmpty(SqStack &S);//判断空 
bool IsFull(SqStack &S);//判断满 
int Length(SqStack &S);//返回长度 
void Push(SqStack &S,int data);//入栈 
int Pop(SqStack &S);//出栈并返回元素 
int GetHead(SqStack &S);//获取栈顶元素 
void Clear(SqStack &S);//清空 
void Traverse(SqStack &S);//遍历 

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
		cout<<"满"<<endl;
		return;
	}
	S.base[S.stacksize++] = data;
}

int Pop(SqStack &S){
	if(IsEmpty(S)){
		cout<<"空"<<endl;
		return -1; 
	}
	return S.base[--S.stacksize];
}

int GetHead(SqStack &S){
	if(IsEmpty(S)){
		cout<<"空"<<endl;
		return -1; 
	}
	return S.base[S.stacksize-1];
}

void Clear(SqStack &S){
	S.stacksize = 0;
}

void Traverse(SqStack &S){
	if(IsEmpty(S)){
		cout<<"空"<<endl;
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


