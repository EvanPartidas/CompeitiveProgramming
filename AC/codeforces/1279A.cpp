#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-->0){
		int arr[3];
		cin>>arr[0]>>arr[1]>>arr[2];
		sort(arr,arr+3);
		if(arr[2]<=arr[1]+arr[0]+1)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
