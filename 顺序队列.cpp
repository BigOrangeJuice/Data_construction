#include <iostream>
using namespace std;
#include <assert.h>
#include <malloc.h>

#define maxsize 100 

typedef struct SqQueue{
	int *base;
	int front;
	int rear;
}SqQueue;

void Init(SqQueue &Q);//初始化 
bool IsEmpty(SqQueue &Q);//判断队空 
bool IsFull(SqQueue &Q);//判断队满 
int Length(SqQueue &Q);//返回队长 
void EnQueue(SqQueue &Q,int data);//入队 
int DeQueue(SqQueue &Q);//出队 
int GetHead(SqQueue &Q);//返回队头元素 
void Clear(SqQueue &Q);//清空 
void Traverse(SqQueue &Q);//遍历 

void Init(SqQueue &Q){
	Q.base = (int*)malloc(sizeof(int)*maxsize);
	Q.front = Q.rear = 0;
}

bool IsEmpty(SqQueue &Q){
	return Q.front == Q.rear;
}

bool IsFull(SqQueue &Q){
	return (Q.rear+1)%maxsize == Q.front;
}

int Length(SqQueue &Q){
	return (Q.rear-Q.front+maxsize)%maxsize;
}

void EnQueue(SqQueue &Q,int data){
	if(IsFull(Q)){
		cout<<"满"<<endl;
		return;
	}
	Q.base[Q.rear] = data;
	Q.rear = (Q.rear+1)%maxsize;
}

int DeQueue(SqQueue &Q){
	if(IsFull(Q)){
		cout<<"空"<<endl;
		return -1;
	}
	int e = Q.base[Q.front];
	Q.front = (Q.front+1)%maxsize;
	return e;
}

int GetHead(SqQueue &Q){
	if(IsFull(Q)){
		cout<<"空"<<endl;
		return -1;
	}
	return Q.base[Q.front];
}

void Clear(SqQueue &Q){
	Q.rear = Q.front;
	Q.base[Q.front] = 0;
}

void MyTraverse(SqQueue Q){
	if(IsEmpty(Q)){
		cout<<"空"<<endl;
		return ;
	}
	while(!IsEmpty(Q)){
		cout<<Q.base[Q.front]<<endl;
		Q.front = (Q.front+1)%maxsize;
	}
}

int main(){
	SqQueue Q;
	Init(Q);
	
	return 0 ;
}
