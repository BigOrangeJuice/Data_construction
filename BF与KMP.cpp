#include <iostream>
using namespace std;
#include <string>

int next[100];
int index_BF(string s,string t,int pos);//暴力回溯 
int index_KMP(string s,string t,int pos);//跳跃比较 
void get_next(string t,int *next);//next数组 
void get_nextval(string t,int *next);//nextval数组 

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

//不论是next还是nextval，针对的都是对于模式串t的运算 
void get_next(string t,int *next){
	int i=0,j=-1;
	int tl=t.length();
	next[0]=-1;
	while(i<tl){
		if(j==-1||t[i]==t[j]){
			++i;++j;
			next[i]=j;//记录此位置有多少左右两侧对称字符的字符对 
		}
		else	j=next[j];//回退到对称字符对的右侧最开始的字符位置
							//当前的next[j]代表的就是对称字符对数 
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


