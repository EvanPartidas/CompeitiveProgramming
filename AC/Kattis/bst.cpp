#include <iostream>
#include <map>


using namespace std;

map<int,int> tree;

int main(){
	int N;
	cin>>N;
	int tmp;
	long long sum=0;
	for(int i=0;i<N;i++){
		cin>>tmp;
		auto lower = tree.lower_bound(tmp);
		if(lower!=tree.begin())
			lower--;
		auto greater = tree.upper_bound(tmp);
		int m = 0;
		if(lower!=tree.end()){
			m=(*lower).second;
		}
		if(greater!=tree.end()){
			m=max(m,(*greater).second);
		}
		tree[tmp]=m+1;
		sum+=m;
		cout<<sum<<endl;
	}
	return 0;
}
