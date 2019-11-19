#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 2e5;

int arr[MAXN];

int main(){
	int N,X;
	cin>>N>>X;
	for(int i=0;i<N;i++)
		cin>>arr[i];
	sort(arr,arr+N);
	int i=0;
	int count = 0;
	while(i<N){
		if(arr[i]+arr[N-1]<=X){
			i++;
			N--;
			count++;
		}
		else{
			N--;
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
