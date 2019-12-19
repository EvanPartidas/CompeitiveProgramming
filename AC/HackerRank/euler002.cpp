#include <iostream>

using namespace std;

typedef unsigned long long ll;

const ll MAXN = 4e16+5;

ll fib[100];
ll dp[100];

int main(){
	int T;
	cin>>T;
	int size=2;
	fib[0]=1;
	fib[1]=1;
	dp[0]=0;
	dp[1]=0;
	while(fib[size-1]<MAXN){
		fib[size]=fib[size-1]+fib[size-2];
		dp[size]=dp[size-1]+(fib[size]%2==0?fib[size]:0);
		size++;
	}
	while(T-->0){
		ll N;
		cin>>N;
		int lo = 0;
		int hi = size;
		while(lo+1<hi){
			int mid = (lo+hi)/2;
			if(fib[mid]<=N)
				lo = mid;
			else
				hi = mid;
		}
		cout<<dp[lo]<<endl;
	}
	return 0;
}
