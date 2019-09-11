#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int dist[20005];

int main(){
	int start,dest;
	cin>>start>>dest;

	if(start==dest){
		cout<<0<<endl;
		return 0;
	}

	q.push(start);


	while(!q.empty()){
		auto pop = q.front();
		q.pop();
		int d1 = pop*2;
		int d2 = pop-1;
		if(d1==dest||d2==dest){
			cout<<dist[pop]+1<<endl;
			break;
		}
		if(d1>0&&d1<20000&&(!dist[d1])){
			q.push(d1);
			dist[d1]=dist[pop]+1;
		}
		if(d2>=0&&d2<20000&&(!dist[d2])){
			q.push(d2);
			dist[d2]=dist[pop]+1;
		}
	}
	return 0;
}
