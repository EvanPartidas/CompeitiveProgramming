#include <iostream>

using namespace std;
typedef long long ll;

const int MAXN = 2e5+5;

ll arr[MAXN];
int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	while(q-->0){
		int a,b;
		cin>>a>>b;
		cout<<(arr[b]-arr[a-1])<<endl;		
	}
	return 0;
}
