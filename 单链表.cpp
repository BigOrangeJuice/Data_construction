#include <iostream>
using namespace std;
#include <malloc.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node,*LinkList;

void Init(LinkList &L);//初始化 
bool IsEmpty(LinkList &L);//判断空 
int Length(LinkList &L);//返回长度 
void Insert(LinkList &L,int key,int value);//插入 
void Insert_tail(LinkList &L,int value);//尾插法 
void Insert_head(LinkList &L,int value);//头插法 
void Modify(LinkList &L,int key,int value);//修改
Node *Get_pro(LinkList &L,int key);//返回前节点 
int Delete_key(LinkList &L,int key);//按位删除并返回此处的值 
void Delete_value(LinkList &L,int value);//按值删除 
void Query(LinkList &L,int value);//查询 
void Clear(LinkList &L);//清空 
void Traverse(LinkList &L);//遍历 

void Init(LinkList &L){
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL;
}

bool IsEmpty(LinkList &L){
	return L->next==NULL;
}

int Length(LinkList &L){
	Node *p = L->next;
	int flag = 0;
	while(p){
		flag++;
		p = p->next;
	}
	return flag;
}

void Insert(LinkList &L,int key,int value){
	if(key<1||key>Length(L)+1){
		cout<<"位置非法"<<endl;
	}
	Node *p = L;
	Node *q = (Node*)malloc(sizeof(Node));
	q->data = value;
	q->next = NULL;
	while(key>1){
		p=p->next;
		key--;
	}
	q->next = p->next;
	p->next = q;
	cout<<"ok"<<endl;
}

void Insert_tail(LinkList &L,int value){
	Node *p = L;
	while(p->next){//注意：p应该是先指向L而不是L的下一位，因为L可能是空表 
		p = p->next;
	}
	Node *q = (Node*)malloc(sizeof(Node));
	q->data = value;
	q->next = NULL;
	p->next = q;
	cout<<"ok"<<endl;
}

void Insert_head(LinkList &L,int value){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = value;
	if(IsEmpty(L)){
		L->next = p;
		p->next = NULL;
		return;
	}
	else{
		p->next = L->next;
		L->next = p;
	}
}

void Modify(LinkList &L,int key,int value){
	if(IsEmpty(L)){
		cout<<"空"<<endl;
	}
	if(key>=1&&key<=Length(L)){
		Node *p = L->next;
		int i = 1;
		while(i<key){
			p = p->next;
			i++;
		}
		p->data = value;
	}
	cout<<"ok"<<endl;
}

Node *Get_pro(LinkList &L,int key){
	if(IsEmpty(L)){
		cout<<"空"<<endl;
	}
	if(key>=1&&key<=Length(L)){
		Node *p = L;
		int i = 1;
		int e = 0;
		while(i<key){
			p = p->next;
			i++;
		}
		return p; 
	}
	return NULL;
}

int Delete_key(LinkList &L,int key){
	Node *p = Get_pro(L,key);
	if(p != NULL){
		int e = p->next->data;
		Node *q = p->next;
		p->next = p->next->next;
		free(q);
		return e;
	}
	cout<<"ok"<<endl;
	return -1;
}

void Delete_value(LinkList &L,int value){
	if(IsEmpty(L)){
		cout<<"空"<<endl;
	}
	Node *p = L->next;
	int flag = 1;
	while(p){
		if(p->data==value)	{Delete_key(L,flag);return;}
		p = p->next;
		flag++;
	}
	cout<<"无果"<<endl;
}

void Query(LinkList &L,int value){
	if(IsEmpty(L)){
		cout<<"空"<<endl;
	}
	Node *p = L->next;
	while(p){
		if(p->data==value)	{cout<<"find it"<<endl;return;}
		p = p->next;
	}
	cout<<"无果"<<endl;
}

void Clear(LinkList &L){
	Node *p = L;
	while(p->next){
		Delete_key(p,1);
	}
	cout<<"ok"<<endl;
}

void Traverse(LinkList &L){
	if(IsEmpty(L)){
		cout<<"空"<<endl;
	}
	Node *p = L->next;
	while(p){
		cout<<p->data<<endl;
		p = p->next;
	}
}

int main(){
	LinkList l;
	Init(l);
	return 0 ;
}

