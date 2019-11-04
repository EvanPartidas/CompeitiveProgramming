#include <iostream>

using namespace std;

const int MAXN=1e5+5;

long long arr[MAXN];

long long X;
int N;
bool sum(int k,long long x){
	if(arr[k-1]>=x)
		return true;
	for(int i=1;i+k<N;i++){
		if(arr[i+k-1]-arr[i-1]>=x)
			return true;
	}
	return false;
}

int main(){
	cin>>N>>X;
	cin>>arr[0];
	for(int i=1;i<N;i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	int lo = 0;
	int hi = N+1;
	while(lo+1<hi){
		int mid = (lo+hi)/2;
		if(sum(mid,X)){
			hi = mid;
		}else{
			lo = mid;
		}
	}
	if(hi>N)
		cout<<-1;
	else
		cout<<hi;
	return 0;
}
