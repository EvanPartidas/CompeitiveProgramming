#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int MAXN = 100005;

int x[MAXN],y[MAXN];

int pointers[MAXN];

int N,pivot,line;

bool cmp_p(int a,int b){
    if(x[a]==x[b]){
            if(y[a]<y[b])
                return true;
            else
                return false;
    }
    if(x[a]<x[b])
        return true;
    else
        return false;
}

#define PI 3.14159265

bool cmp_r(int a,int b){//Radial Comparators
    if(a==pivot)
        return false;
    if(b==pivot)
        return true;
    double va = atan2(x[a]-x[pivot],y[a]-y[pivot]);
    double vb = atan2(x[b]-x[pivot],y[b]-y[pivot]);
    return  va<vb;
}

int main(){
    int i;
    cin>>N;
    pivot = 0;
    for(i=0;i<N;i++){
        cin>>x[i]>>y[i];
        pointers[i]=i;
        if(cmp_p(i,pivot)){
            pivot = i;
        }
    }

    sort(pointers,pointers+N,cmp_r);
//    for(i=0;i<N;i++)
//        printf("%d\n",pointers[i]+1);

    printf("%d %d\n",pivot+1,pointers[N/2 - 1]+1);
}
