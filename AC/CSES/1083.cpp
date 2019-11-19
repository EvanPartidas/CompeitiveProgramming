#include <iostream>
#include <set>

using namespace std;

set<int> tree;

int main(){
	
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
		tree.insert(i);
	for(int i=1;i<N;i++){
		int tmp;
		cin>>tmp;
		tree.erase(tmp);
	}
	cout<<*(tree.begin())<<endl;
	return 0;
}
