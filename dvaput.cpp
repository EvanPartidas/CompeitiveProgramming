#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 100000;

int N,C[MAXN],RA[MAXN],TMP[MAXN],SA[MAXN],LCP[MAXN];
char STR[MAXN];

void countsort(int k,int size){//Stable Countsort
    int i;
    for(i=0;i<size;i++)
		C[i]=0;
    for(i=0;i<N;i++)
        C[i+k<N?RA[i+k]:0]++;    
    for(i=1;i<size;i++)
        C[i]+=C[i-1];
    for(i=N-1;i>=0;i--)
        TMP[--C[SA[i]+k<N?RA[SA[i]+k]:0]] = SA[i];
    for(i=0;i<N;i++)
        SA[i]=TMP[i];
}

void initSA(){
	int i,k=1,r;
	for(i=0;i<N;i++)
		RA[i]=STR[i],SA[i]=i;
	countsort(k=1,300);//Initially, sort by ascii values
	countsort(0,300);
	for(k=2;k<N;k<<=1){
		TMP[SA[0]]=r=0;
		for(i=1;i<N;i++){
			TMP[SA[i]]=
				(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
		}
		for (i = 0; i < N; i++)
                	RA[i] = TMP[i];
            	if (RA[SA[N-1]] == N-1) break;
		countsort(k,N);
		countsort(0,N);
	}
}

int lcp(){
	int len=0;
	int prefix=0;
	int i;
	for(i=1;i<N;i++)
		TMP[SA[i]]=SA[i-1];
	for(i = 1;i<N;i++){
		while(STR[i+len]==STR[TMP[i]+len]) len++;
		prefix = max(len,prefix);
		len = max(len-1,0);
	}
	return prefix;
}

int main(){
	cin>>N;
	cin>>STR;
	STR[N++]='$';
	initSA();//O(NlogN)
	cout<<lcp()<<endl;//O(N)
	return 0;
}
