#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(){
	cin>>N;
	vector<int> lis;
	int x;
	while(N-->0){
		cin>>x;
		auto it = lower_bound(lis.begin(),lis.end(),x);
		if(it==lis.end())
			lis.push_back(x);
		else
			*it=x;
	}
	cout<<lis.size();
	return 0;
}
