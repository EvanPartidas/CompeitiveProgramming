#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 10e5+5;
int arr[MAXN];

int main(){
	int t;
	cin>>t;
	while(t-->0){
		int N,s;
		cin>>N>>s;
		int maxdex = 1;
		int i;
		for(i=1;i<=N;i++){
			cin>>arr[i];
			if(arr[i]>arr[maxdex]-arr[maxdex-1])
				maxdex=i;
			arr[i]+=arr[i-1];
			if(arr[i]>s){
				i++;
				while(i<=N){
					cin>>arr[i++];
				}
				cout<<maxdex<<endl;
				i=0;
				break;
			}
		}
		if(i==N+1)
			cout<<0<<endl;	
			
	}
	return 0;
}
