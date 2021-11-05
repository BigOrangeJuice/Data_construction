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

void Init(SqQueue &Q);//��ʼ�� 
bool IsEmpty(SqQueue &Q);//�ж϶ӿ� 
bool IsFull(SqQueue &Q);//�ж϶��� 
int Length(SqQueue &Q);//���ضӳ� 
void EnQueue(SqQueue &Q,int data);//��� 
int DeQueue(SqQueue &Q);//���� 
int GetHead(SqQueue &Q);//���ض�ͷԪ�� 
void Clear(SqQueue &Q);//��� 
void Traverse(SqQueue &Q);//���� 

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
		cout<<"��"<<endl;
		return;
	}
	Q.base[Q.rear] = data;
	Q.rear = (Q.rear+1)%maxsize;
}

int DeQueue(SqQueue &Q){
	if(IsFull(Q)){
		cout<<"��"<<endl;
		return -1;
	}
	int e = Q.base[Q.front];
	Q.front = (Q.front+1)%maxsize;
	return e;
}

int GetHead(SqQueue &Q){
	if(IsFull(Q)){
		cout<<"��"<<endl;
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
		cout<<"��"<<endl;
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
