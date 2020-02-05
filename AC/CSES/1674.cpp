#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int MAXN = 2e5+5;

vector<int> children[MAXN];
int count[MAXN];

int traverse(int node){
	int sum = 0;
	for(auto dest:children[node]){
		sum+=traverse(dest);
	}
	return 1+(count[node]=sum);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	cin>>N;
	for(int i=2;i<=N;i++){
		int a;
		cin>>a;
		children[a].push_back(i);
	}
	traverse(1);
	for(int i=1;i<=N;i++){
		cout<<count[i]<<" ";
	}
	
	return 0;
}
