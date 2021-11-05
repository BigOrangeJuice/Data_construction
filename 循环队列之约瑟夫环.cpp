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

int Joseph(SqQueue &Q){
	cout<<"����Ԫ�������ͺ���";
	int sum,target;
	int count=1;
	cin>>sum>>target;
	for(int i=1;i<=sum;++i){
		EnQueue(Q,i);
	}
	while(!IsEmpty(Q)){
		if(count%target==0){
			cout<<DeQueue(Q)<<endl;
		}
		else{
			EnQueue(Q,DeQueue(Q));
		}
		count++;
	}
} 

int main(){
	SqQueue Q;
	Init(Q);
	Joseph(Q);
	return 0 ;
}
