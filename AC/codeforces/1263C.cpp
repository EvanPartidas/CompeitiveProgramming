#include <iostream>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

set<int> ls;

int main(){
	int t;
	cin>>t;
	while(t-->0){
		ls.clear();
		ls.insert(0);
		int n;
		cin>>n;
		int limit = sqrt(n);
		for(int i=1;i<=limit;i++){
			ls.insert(i);
			ls.insert(n/i);
		}
		if(n>1)
			ls.insert(n);
		cout<<ls.size()<<endl;
		for(int x:ls)
			cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
