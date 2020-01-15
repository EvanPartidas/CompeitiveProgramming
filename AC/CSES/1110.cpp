#include <iostream>
#include <string>
#include <string.h>

using namespace std;
typedef long long ll;

const int MAXN = 1e6+5;


int N,C[MAXN],RA[MAXN],TMP[MAXN],SA[MAXN],S2;
char STR[MAXN];

int countsort(int k,int size){//Stable Countsort
    int i,ret=0;
    for(i=0;i<size;i++)
		C[i]=0;
    for(i=0;i<S2;i++)
        C[i+k<N?RA[i+k]:RA[i+k-N]]++;    
    for(i=0;i<size;i++){
		/*if(C[i]>0&&ret==0){
			S2 = C[i];
		}*/
		//ret = max(C[i],ret);
		if(i>0)
			C[i]+=C[i-1];
	}
    for(i=S2-1;i>=0;i--)
        TMP[--C[SA[i]+k<N?RA[SA[i]+k]:RA[SA[i]+k-N]]] = SA[i];
    for(i=0;i<N;i++)
        SA[i]=TMP[i];
    return ret;
}

void initSA(){
	int i,k=1,r;
	for(i=0;i<N;i++)
		RA[i]=STR[i],SA[i]=i;
	int size=N;
	S2=N;
	for(k=1;k<N;k<<=1){
		if(k==1){
			countsort(k,300);//Initially, sort by ascii values
			countsort(0,300);
		}
		else{
			countsort(k,size+1);
			countsort(0,size+1);	
		}
		TMP[SA[0]]=r=0;
		for(i=1;i<N;i++){
			TMP[SA[i]]=
				(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k<N?SA[i]+k:SA[i]+k-N]==RA[SA[i-1]+k<N?SA[i-1]+k:SA[i-1]+k-N])?r:++r;
		}
		size = TMP[SA[N-1]];
		for (i = 0; i < N; i++)
                	RA[i] = TMP[i];
        if (RA[SA[N-1]] == N-1) break;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>STR;
	N = strlen(STR);
	initSA();
	cout<<(STR+SA[0]);
	STR[SA[0]]=0;
	cout<<STR;
	return 0;
}
