#include <iostream>
#include <string.h>
using namespace std;
#define max 1001

typedef struct SqList {
	int base[max];
	int length;
}SqList;

void Init(SqList& L);//初始化 
bool IsEmpty(SqList L);//判断空
bool IsFull(SqList L);//判断满 
int Query(SqList L);//查找并返回位置 
void Insert(SqList& L, int key, int value);//插入 
int Delete_key(SqList& L, int key);//按位删除并返回元素 
int Delete_value(SqList& L, int value);//按值删除首次出现的相同元素并返回位置【非索引值】 
void Modify(SqList& L, int key);//修改 
int Length(SqList L);//返回长度 
void Clear(SqList& L);//清空 
void Traverse(SqList L); //遍历 

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
		cout << "空！" << endl;
		return -1;
	}
	for (int i = 0; i < L.length; ++i) {
		if (L.base[i] == value) {
			return i + 1;
		}
	}
	cout << "无果！" << endl;
	return -1;
}

void Insert(SqList& L, int key, int value) {
	if (IsFull(L)) {
		cout << "满！" << endl;
		return;
	}
	if (key<1 || key>L.length + 1 || key > max - 1) {
		cout << "位置非法！" << endl;
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
		cout << "空！" << endl;
		return -1;
	}
	if (key<1 || key>L.length) {
		cout << "位置非法！" << endl;
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
		cout << "空！" << endl;
		return -1;
	}
	int key = Query(L, value);
	if (key != -1)	Delete_key(L, key);
	cout << "无果！" << endl;
	return -1;
}

void Modify(SqList& L, int key, int value) {
	if (IsEmpty(L)) {
		cout << "空！" << endl;
		return;
	}
	if (key<1 || key>L.length) {
		cout << "位置非法！" << endl;
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
		cout << "空！" << endl;
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

