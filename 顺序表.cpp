#include <iostream>
#include <string.h>
using namespace std;
#define max 1001

typedef struct SqList {
	int base[max];
	int length;
}SqList;

void Init(SqList& L);//��ʼ�� 
bool IsEmpty(SqList L);//�жϿ�
bool IsFull(SqList L);//�ж��� 
int Query(SqList L);//���Ҳ�����λ�� 
void Insert(SqList& L, int key, int value);//���� 
int Delete_key(SqList& L, int key);//��λɾ��������Ԫ�� 
int Delete_value(SqList& L, int value);//��ֵɾ���״γ��ֵ���ͬԪ�ز�����λ�á�������ֵ�� 
void Modify(SqList& L, int key);//�޸� 
int Length(SqList L);//���س��� 
void Clear(SqList& L);//��� 
void Traverse(SqList L); //���� 

void Init(SqList& L) {
	memset(L.base, 0, max);
	L.length = 0;
}

bool IsEmpty(SqList L) {
	return L.length == 0;
}

bool IsFull(SqList L) {
	return L.length == max;
}

int Query(SqList L, int value) {
	if (IsEmpty(L)) {
		cout << "�գ�" << endl;
		return -1;
	}
	for (int i = 0; i < L.length; ++i) {
		if (L.base[i] == value) {
			return i + 1;
		}
	}
	cout << "�޹���" << endl;
	return -1;
}

void Insert(SqList& L, int key, int value) {
	if (IsFull(L)) {
		cout << "����" << endl;
		return;
	}
	if (key<1 || key>L.length + 1 || key > max - 1) {
		cout << "λ�÷Ƿ���" << endl;
		return;
	}
	int i = 0;
	for (i = L.length - 1; i >= key - 1; --i) {
		L.base[i + 1] = L.base[i];
	}
	L.base[i + 1] = value;
	L.length++;
	cout << L.length;
	cout << "ok!" << endl;
}

int Delete_key(SqList& L, int key) {
	if (IsEmpty(L)) {
		cout << "�գ�" << endl;
		return -1;
	}
	if (key<1 || key>L.length) {
		cout << "λ�÷Ƿ���" << endl;
		return -1;
	}
	int i = 0;
	int e = L.base[key - 1];
	for (i = key - 1; i < L.length; ++i) {
		L.base[i] = L.base[i + 1];
	}
	L.length--;
	cout << "ok!" << endl;
	return e;
}

int Delete_value(SqList& L, int value) {
	if (IsEmpty(L)) {
		cout << "�գ�" << endl;
		return -1;
	}
	int key = Query(L, value);
	if (key != -1)	Delete_key(L, key);
	cout << "�޹���" << endl;
	return -1;
}

void Modify(SqList& L, int key, int value) {
	if (IsEmpty(L)) {
		cout << "�գ�" << endl;
		return;
	}
	if (key<1 || key>L.length) {
		cout << "λ�÷Ƿ���" << endl;
		return;
	}
	L.base[key - 1] = value;
}

int Length(SqList L) {
	return L.length;
}

void Clear(SqList& L) {
	L.length = 0;
	return;
}

void Traverse(SqList L) {
	if (IsEmpty(L)) {
		cout << "�գ�" << endl;
		return;
	}
	for (int i = 0; i < L.length; ++i) {
		cout << L.base[i] << endl;
	}
}

int main() {
	SqList l;
	Init(l);

	return 0;
}

