#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 100000;

int N,C[MAXN],TRA[MAXN],RA[MAXN],TSA[MAXN],SA[MAXN];
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
        TSA[--C[SA[i]+k<N?RA[SA[i]+k]:0]] = SA[i];
    for(i=0;i<N;i++)
        SA[i]=TSA[i];
}

void print(){
	puts("Printing...");
	for(int i=0;i<N;i++){
		cout<<(STR+SA[i])<<endl;
	}	
}

void initSA(){
    int i,k,r;
    for(i=0;i<N;i++)
        RA[i]=STR[i],SA[i]=i;
    for(k=1;k<N;k<<=1){
            countsort(k,300);
            countsort(0,300);
            TRA[SA[0]]=r=0;
            for(i=1;i<N;i++){
		TRA[SA[i]]=
			(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;

            }
            for (i = 0; i < N; i++)
                RA[i] = TRA[i];
            if (RA[SA[N-1]] == N-1) break;
    }
}

int lcp(){
	
}

int main(){
	cin>>N;
	cin>>STR;
	STR[N++]='$';
	initSA();
	print();
	return 0;
}
