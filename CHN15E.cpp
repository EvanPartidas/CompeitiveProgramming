#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

const int MAXN = 10005;
unordered_set<int> adj[MAXN],res[MAXN];

int outedges[MAXN],//Outedges
val[MAXN],
topsort[MAXN];
int N,M,topSize;

void DFS(int node){
    for(auto child:res[node]){
        printf("%d %d\n",node+1,child+1);
        DFS(child);
    }
}

int main(){

    int T,i,j,k;
    cin>>T;
    while(T-->0){
        cin>>N>>M;

        topSize = 0;
        for(i=0;i<N;i++){
            adj[i].clear();
            res[i].clear();
            outedges[i] = 0;
        }

        for(i=0;i<M;i++){
            cin>>j>>k;
            j--;
            k--;
            adj[k].insert(j);//Reversed
            outedges[j]++;
        }

        int root;
        //Topsort setup
        for(i=0;i<N;i++){
            if(!outedges[i]){
                val[i] = topSize;
                topsort[topSize++]=i;
            }
            if(adj[i].size()==0)
                root = i;
        }

        //Topsorting
        for(i=0;i<topSize;i++){
                //printf("Topsort: %d\n",topsort[i]);
                for(auto dest : adj[topsort[i]]){
                        outedges[dest]--;
                        if(!outedges[dest]){
                            val[dest] = topSize;
                            topsort[topSize++] = dest;
                        }
                }
        }

        int cur;
        for(i=0;i<N;i++){
            cur = topsort[i];
            //printf("%d inedges: %d\n",cur+1,adj[cur].size());
            if(adj[cur].empty())
                continue;
            int earliest = *adj[cur].begin();
            if(adj[cur].size()==1){
                res[earliest].insert(cur);
            }
            else{
                for(auto parent:adj[cur])
                        if(val[parent]>val[earliest])
                            earliest = parent;
                if(outedges[cur]){
                    int parent = outedges[cur]-1;
                    for(auto babushka:adj[parent]){
                        if(babushka==earliest){
                            res[babushka].insert(parent);
                            res[parent].insert(cur);
                            outedges[parent] = babushka+1;
                            goto end_loop;
                        }
                    }
                }
                else
                    for(auto parent:adj[cur]){
                        for(auto babushka:adj[parent]){
                            if(babushka==earliest){
                                //printf("%d %d %d\n",babushka+1,parent+1,cur+1);
                                res[babushka].insert(parent);
                                res[parent].insert(cur);
                                outedges[parent] = babushka+1;
                                goto end_loop;
                            }
                        }
                    }
            }
            end_loop:
                continue;
        }
        DFS(root);
    }
    return 0;
}
