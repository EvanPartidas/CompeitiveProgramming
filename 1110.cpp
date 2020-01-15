#include <iostream>
#include <string>
#include <string.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e6+5;

int C[27],TMP[MAXN],SA[MAXN],N,cpy[MAXN];
char str[MAXN];
int countsort(int k,int size){//Stable Countsort
    int i,ret=0;
    for(i=0;i<27;i++)
		C[i]=0;
    for(i=0;i<size;i++)
        C[SA[i]+k<N?cpy[SA[i]+k]:cpy[SA[i]+k-N]]++;   
    for(i=0;i<27;i++){
		if(C[i]>0&&ret==0)
			ret = C[i];
		if(i>0)
			C[i]+=C[i-1];
	}
    for(i=size-1;i>=0;i--)
        TMP[--C[SA[i]+k<N?cpy[SA[i]+k]:cpy[SA[i]+k-N]]] = SA[i];
    for(i=0;i<size;i++)
        SA[i]=TMP[i];
    return ret;
}

int main(){
	cin>>str;
	N = strlen(str);
	for(int i=0;i<N;i++){
		cpy[i] = str[i]-'a';
		SA[i] = i;
	}
	int size = N,i=0;
	while(size>1&&i<N){
		size = countsort(i++,size);
		printf("%d %d\n",size,i);
	}
	cout<<(str+SA[0]);
	str[SA[0]]=0;
	cout<<str;
	return 0;
}
