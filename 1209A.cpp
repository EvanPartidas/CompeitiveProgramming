#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

const int MAXN= 105;

int seq[MAXN];

vector<int> map[MAXN];

bitset<MAXN> set;

int N;

int main(){

	cin>>N;

	for(int i=0;i<N;i++)
		cin>>seq[i];

	sort(seq,seq+N);

	int count = 0;

	for(int i=0;i<N;i++){
		if(set[seq[i]])
			continue;
		set.set(seq[i]);
		for(int mul=1;mul*seq[i]<=100;mul++){
			map[seq[i]].push_back(mul*seq[i]);
			set.set(mul*seq[i]);
		}
		count++;
	}

	cout<<count;

	return 0;
}
