
const int MAXN = 100000;

int N,C[MAXN],TRA[MAXN],RA[MAXN],TSA[MAXN],SA[MAXN],STR[MAXN];

int countsort(int k,int size){
    int i;
    memset(C,0,size);
    for(i=0;i<N;i++)
        C[i+k<N?RA[i+k]:0]++;
    for(i=1;i<size;i++)
        C[i]+=C[i-1];
    for(i=0;i<N;i++)
        TSA[--C[i+k<N?i+k:0]] = SA[i];
    for(i=0;i<N;i++)
        SA[i]=TSA[i];
}

void initSA(){
    int i,j,k,r;
    for(i=0;i<N;i++)
        RA[i]=STR[i],SA[i]=i;
    for(k=1;k<N;k<<=1){
            countsort(k);//Reverses the array stably
            countsort(0);//Stabilizes the array (and is also necessary)
            TRA[SA[0]]=r=0;
            for(i=1;i<N;i++){
                if(N-SA[i]<k)
                    TRA[i]=0;
                else
                    TRA[SA[i]]=
                        (RA[SA[i]]==RA[SA[i-1]]&&RA[SA[i]+k]==RA[SA[i]+k])?r:++r;

            }
            for (i = 0; i < n; i++)
                RA[i] = TRA[i];
            if (RA[SA[n-1]] == n-1) break;
    }
}
