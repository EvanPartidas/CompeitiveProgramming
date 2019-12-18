#include <iostream>

using namespace std;

int main(){
	int arr[]= {2,4,1,3};
	int N;
	cin>>N;
	if(N==1){
		cout<<1;
		return 0;
	}
	if(N<4){
		puts("NO SOLUTION");
		return 0;
	}
	for(int i=5;i<=N;i+=2)
		cout<<i<<" ";
	for(int i=0;i<4;i++)
		cout<<arr[i]<<" ";
	for(int i=6;i<=N;i+=2)
		cout<<i<<" ";
	return 0;
}
