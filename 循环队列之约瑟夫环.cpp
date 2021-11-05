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

int Joseph(SqQueue &Q){
	cout<<"输入元素总数和喊号";
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
