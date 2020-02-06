/**
 * The below program uses a simple yet extremely clever technique
 * that as far as I know has no name. The technique involves using  
 * a "postorder" traversal of a tree to provide range indexes for every 
 * node. These indexes can then be used in a regular array for any
 * regular range query (Sums, mult, XOR, etc). 
 */

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MAXF = 4e5+5;
const int MAXN = 2e5+5;

ll fen[MAXF];

ll sum(int ind){
	ll ret = 0;
	while(ind>0){
		ret+=fen[ind];
		ind-=ind&-ind;
	}
	return ret;
}

void update(int ind, ll delta){
	while(ind<=MAXF){
		fen[ind] += delta;
		ind+=ind&-ind;
	}
}

vector<int> graph[MAXN];
ll val[MAXN];
int pre[MAXN],post[MAXN];
int parents[MAXN];

int postorder(int node,int parent,int index){
	pre[node]=index++;
	for(auto child:graph[node]){
		if(child==parent) continue;
		parents[child]=node;
		index = postorder(child,node,index);
	}
	return 1+(post[node]=index);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N,Q;
	cin>>N>>Q;
	for(int i=1;i<=N;i++)
		cin>>val[i];
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	postorder(1,1,0);
	for(int i=1;i<=N;i++)
		update(post[i],val[i]);
	while(Q-->0){
		int q;
		cin>>q;
		if(q==1){
			int n,x;
			cin>>n>>x;
			ll delta = x-val[n];
			val[n]=x;
			update(post[n],delta);
		}
		else{
			int n;
			cin>>n;
			cout<<(sum(post[n])-sum(pre[n]))<<endl;
		}
	}
	
	return 0;
}
