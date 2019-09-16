#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 200005;

int seq[MAXN];

int pointers[MAXN];

int fin[MAXN];

set<int> found;

int T,N;

bool cmp(int a,int b){
	return seq[a]<seq[b];
}

int main(){

	ios_base::sync_with_stdio(false);

	cin>>T;

	int i;
	char c;
	while(T-->0){
		cin>>N;

		for(i=0;i<N;i++){
			cin>>c;
			seq[i] = c-'0';
			pointers[i] = i;
		}

		stable_sort(pointers,pointers+N,cmp);

		int prev=-1;

		found.clear();


		bool red = false;
		bool imposs = false;
		for(i=0;i<N;i++){
			cout<<seq[pointers[i]]<<"-"<<pointers[i]<<" ";
			if(prev>pointers[i])
				red = true;
			if(red){
				fin[pointers[i]] = 2;
				if(found.upper_bound(pointers[i])!=found.end()){
					imposs = true;
					break;
				}
				found.insert(pointers[i]);
			}
			else{
				prev = pointers[i];
				fin[pointers[i]] = 1;
			}
		}

		if(imposs)
			cout<<"-";
		else
			for(i=0;i<N;i++)
				cout<<fin[i];
		cout<<endl;
	}
	return 0;
}
