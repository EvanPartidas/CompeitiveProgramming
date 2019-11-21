#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN= 2e5;
int arr[MAXN];


int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	sort(arr,arr+N);
	long long sum = 0;
	for(int i=0;i<N;i++){
		sum+=abs(arr[i]-arr[N/2]);
	}
	cout<<sum<<endl;
	return 0;
}
