#include <iostream>
#include <vector>
 
using namespace std;
 
const int MAXN = 2e5+5;
 
vector<int> graph[MAXN];
int dist[MAXN];
int maxDist=0;
 
int dfs(int node,int p){
    int ret = node;
    for(int dest:graph[node]){
        if(dest==p)
            continue;
        dist[dest]=dist[node]+1;
        maxDist = max(dist[dest],maxDist);
        int n = dfs(dest,node);
        if(dist[n]>dist[ret])
            ret = n;
    }
    return ret;
}
 
int main() {
    int N;
    cin>>N;
    for(int i=1;i<N;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dist[1]=0;
    int n = dfs(1,1);
    dist[n]=0;
    n = dfs(n,n);
    cout<<maxDist;
    return 0;
}
