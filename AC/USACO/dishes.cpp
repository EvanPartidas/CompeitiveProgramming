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
	priority_queue<int,vector<int>,greater<int>> queue;
	for(i=0;i<len;i++)
		queue.push(plateOrder[i]);

//	cout<<"Len "<<len<<endl;
	for(i=0;i<len;i++){
		int lo = mindex;
		int hi = plateStacks.size()-1;
		//Right here we are looking for an lower_bound.
		//We need to find the closest index that
		//can hold our value.
		while(lo<hi){
			int mid = (lo+hi)/2;
			if(plateStacks[mid].top()<plateOrder[i]){
				lo = mid+1;
//				cout<<i<<": Too small"<<endl;
			}else{
				hi = mid;
//				cout<<i<<": Possible"<<endl;
			}
		}
		if(mindex<plateStacks.size()&&plateStacks[lo].top()<plateOrder[i])
			lo++;
		if(lo==plateStacks.size())
			plateStacks.push_back(stack<int>());
		plateStacks[lo].push(plateOrder[i]);
//		cout<<plateStacks[mindex].top()<<"<- Min ->"<<queue.top()<<endl;
                while(mindex<plateStacks.size()&&plateStacks[mindex].top()==queue.top()){
//			cout<<"Popping"<<endl;
			plateStacks[mindex].pop();
			queue.pop();
			if(plateStacks[mindex].empty())
				mindex++;
		}

	}
//	cout<<"Works: "<<queue.empty()<<endl;
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
	//This is an upper_bound binary search
	//We want the longest working length possible.
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
