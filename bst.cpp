#include <iostream>
#include <map>


using namespace std;

map<int> tree;

int main(){
	int N;
	cin>>N;
	int tmp;
	for(int i=0;i<N;i++){
		cin>>tmp;
		auto lower = tree.lower_bound(tmp);
		auto greater = tree.upper_bound(tmp);
		
	}
	return 0;
}
