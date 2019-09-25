#include <iostream>

using namespace std;

const int MAXN = 10005;

vector<int> adj[];

int deg[MAXN],//Inedges
pointers[MAXN],
pathcount[MAXN];
int N,M;


bool pthcmp(int a,int b){
    return pathcount[a]<pathcount[b];
}

int main(){

    int T,i,j,k;
    cin>>T;
    while(T-->0){
        cin>>N>>M;

        for(i=0;i<N;i++){
            adj[i].clear();
            deg[i] = 0;
            pointers[i] = i;
            pathcount[i] = 0;
        }

        for(i=0;i<N;i++){
            cin>>j>>k;
            adj[j].push_back(k);
            deg[k]++;
        }
    }

    for(){

    }
    pathcount[0]=1;
    for(i=0;i<N;i++){
        for(auto a:adj[pointers[i]]){
            pathcount[a]+=pathcount[pointers[i]];
        }
    }
    sort(pointers,pointers+N,pthcmp);

    return 0;
}
