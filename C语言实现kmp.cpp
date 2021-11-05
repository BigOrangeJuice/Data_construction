#include <stdio.h>
#include <string.h>

int next[100]; 
int index_KMP(char s[],char t[],int pos);//跳跃比较 
void get_next(char t[],int *next);//next数组 

int index_KMP(char s[],char t[],int pos){
	int i=pos-1,j=0;
	int sl=strlen(s),tl=strlen(t);
	get_next(t,next);
	while(i<sl&&j<tl){
		if(j==-1||s[i]==t[j]){
			++i;++j;
		}
		else	j=next[j];
	}
	if(j>=tl)	return i-tl+1;
	return 0;
}

void get_next(char t[],int *next){
	int i=0,j=-1;
	int tl=strlen(t);
	next[0]=-1;
	while(i<tl){
		if(j==-1||t[i]==t[j]){
			++i;++j;
			next[i]=j;
		}
		else j=next[j];
	}
}

int main(){
	char s[100]="helloworld";
	char t[100]="lo";
	printf("%d\n",index_KMP(s,t,1));
	return 0 ;
}


