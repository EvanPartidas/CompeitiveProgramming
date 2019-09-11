#include <iostream>
#include <queue>


using namespace std;


int main(){

	ios_base::sync_with_stdio(false);
	queue<int> q;
	int i,tmp;
	char map[16];
	for(i=0;i<10;i++)
		map[i]=i+'0';
	for(i=0;i<6;i++)
		map[i+10]=i+'A';
	char num;
	while(1){
		cin>>num;
		if(num<' ')
			break;
		num-='0';
		for(i=2;i>=0;i--){
			tmp = (num>>i)&1;
			q.push(tmp);
		}
	}
	int print,sub;
	bool first = true;
	while(!q.empty()){
		print = 0;
		sub = q.size()%4==0?0:4-q.size()%4;
		for(i=3-sub;i>=0;i--){
			tmp = (q.front())<<i;
			print += tmp;
			q.pop();
		}
		if(first&&print==0&&!q.empty())
			continue;
		first = false;
		cout<<map[print];
	}
	return 0;
}
