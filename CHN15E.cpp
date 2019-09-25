#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 10005;

vector<int> adj[MAXN],res[MAXN],rev[MAXN];

int indeg1[MAXN],//Inedges
indeg2[MAXN],
pointers[MAXN],
topsort[MAXN],
pathcount[MAXN];
int N,M,topSize;


bool pthcmp(int a,int b){
    return pathcount[a]>pathcount[b];
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
            rev[i].clear();
            indeg1[i] = 0;
            indeg2[i] = 0;
            pointers[i] = i;
            pathcount[i] = 0;
        }

        for(i=0;i<N;i++){
            cin>>j>>k;
            j--;
            k--;
            adj[j].push_back(k);
            adj[k].push_back(j);
            indeg1[k]++;
            indeg2[k]++;
        }
    }
    //Topsort setup
    for(i=0;i<N;i++){
        if(!indeg1[i])
            topsort[topSize++]=i;
    }

    //Topsorting
    for(i=0;i<topSize;i++){
            for(auto dest : adj[topsort[i]]){
                    indeg2[dest]--;
                    if(!indeg2[dest])
                        topsort[topSize++] = dest;
            }
    }

    pathcount[0]=1;
    for(i=0;i<N;i++){
        for(auto a:adj[topsort[i]]){
            pathcount[a]+=pathcount[topsort[i]];
        }
    }
    sort(pointers,pointers+N,pthcmp);

    //okay, now the topsort array is gonna become an inverted pointer array

    for(i=0;i<N;i++){
        topsort[pointers[i]] = i;
        if(!indeg1[pointers[i]])
            continue;
        int earliest = rev[pointers[i]][0];
        for(auto parent:rev[pointers[i]]){
                if(topsort[parent]<topsort[pointers[i]])
                    earliest = parent;
        }
        for(auto dest:adj[earliest]){
            for(auto d2:adj[dest]){
                if(d2==pointers[i]){
                    res[dest].push_back(d2);
                    indeg1[d2] = 0;
                    goto walktwo;
                }
            }
        }
        walktwo:
            continue;
    }
    return 0;
}
