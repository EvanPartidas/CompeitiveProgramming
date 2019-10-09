#include <iostream>
#include <bitset>

using namespace std;

const int MAXN = 1e9+5;

bitset<MAXN> set;

int main(){

	int n;
	cin>>n;
	int count = 0;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(!set[num])
			count++;
		set.set(num);
	}
	cout<<count;
	return 0;
}
