#include <iostream>
using namespace std;
#include <string>

int next[100];
int index_BF(string s,string t,int pos);//�������� 
int index_KMP(string s,string t,int pos);//��Ծ�Ƚ� 
void get_next(string t,int *next);//next���� 
void get_nextval(string t,int *next);//nextval���� 

int index_BF(string s,string t,int pos){
	int i = pos-1,j = 0;
	int sl = s.length(),tl = t.length();
	int flag = 0; 
	while(i<sl&&j<tl){
		if(s[i]==t[j]){
			i++;j++;
		}
		else{
			i=i-j+1;
			j=0;
		}
		flag++;
	}
	cout<<"BF:"<<flag<<endl;
	if(j>=tl)	return i-tl+1;
	return 0;
}

int index_KMP(string s,string t,int pos){
	int i = pos-1,j = 0;
	get_nextval(t,next);
	int sl = s.length(),tl = t.length();
	int flag = 0;
	while(i<sl&&j<tl){
		if(j==-1||s[i]==t[j]){ 
			i++;j++;
		}
		else{
			j = next[j];
		}
		flag++;
	}
	cout<<"kmp:"<<flag<<endl;
	if(j>=tl)	return i-tl+1;
	return 0;
}

//������next����nextval����ԵĶ��Ƕ���ģʽ��t������ 
void get_next(string t,int *next){
	int i=0,j=-1;
	int tl=t.length();
	next[0]=-1;
	while(i<tl){
		if(j==-1||t[i]==t[j]){
			++i;++j;
			next[i]=j;//��¼��λ���ж�����������Գ��ַ����ַ��� 
		}
		else	j=next[j];//���˵��Գ��ַ��Ե��Ҳ��ʼ���ַ�λ��
							//��ǰ��next[j]����ľ��ǶԳ��ַ����� 
	}
}

void get_nextval(string t,int *next){
	int i=0,j=-1;
	int tl=t.length();
	next[0]=-1;
	while(i<tl){
		if(j==-1||t[i]==t[j]){
			++i;++j;
			if(t[i]==t[j])	next[i]=next[j];
			else	next[i]=j;
		}
		else	j=next[j];
	}
}

int main(){
	string s="aaadaaab";
	string t="aaab";
	cout<<index_BF(s,t,1)<<endl;
	cout<<index_KMP(s,t,1)<<endl;
	return 0 ;
}


