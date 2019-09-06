#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;

int plateOrder[MAXN];

vector<stack<int>> plateStacks;

int N;

bool sizeWorks(int len){
	int i,mindex=0;
	vector<stack<int>> plateStacks;
	priority_queue<int> queue;
	for(i=0;i<len;i++)
		queue.push(plateOrder[i]);

	cout<<"Len "<<len<<endl;
	for(i=0;i<len;i++){
		cout<<mindex<<" "<<plateStacks.size()<<endl;
		cout<<"Num: "<<plateOrder[i]<<endl;
		int lo = mindex;
		int hi = plateStacks.size();
		while(lo+1<hi){
			int mid = (lo+hi)/2;
			if(plateStacks[mid].top()>plateOrder[i])
				lo = mid;
			else
				hi = mid;
		}
		if(plateStacks[lo].top()<plateOrder[i])
			lo++;
		cout<<" lo: "<<lo<<endl;
		if(lo==plateStacks.size())
			plateStacks.push_back(stack<int>());
		plateStacks[lo].push(plateOrder[i]);
                while(mindex<plateStacks.size()&&plateStacks[mindex].top()==queue.top()){
			cout<<"Popping"<<endl;
			plateStacks[mindex].pop();
			queue.pop();
			if(plateStacks[mindex].empty())
				mindex++;
		}
		cout<<"Cool"<<endl;

	}
	return queue.empty();
}

int main(){

	int i;

	ifstream in;
	ofstream out;
	in.open("dishes.in");
	out.open("dishes.out");

	in>>N;

	for(i=0;i<N;i++)
		in>>plateOrder[i];

	int lo = 0;
	int hi = N+1;
	while(lo+1<hi){
		int mid = (lo+hi)/2;
		if(sizeWorks(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout<<lo;
	out<<lo;
	return 0;
}
