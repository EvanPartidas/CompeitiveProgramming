#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200005;

vector<int> sol;
int arr[MAXN];
int N;

int main(){
	cin>>N;
	int i;
	long long sum=0;
	for(i=0;i<N;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	for(i=0;i<N;i++){
		double mean = (sum-arr[i])/double(N-1);
		if(mean==arr[i])
			sol.push_back(i+1);
	}
	cout<<sol.size()<<endl;
	for(int num:sol)
		cout<<num<<" ";
	return 0;
}
