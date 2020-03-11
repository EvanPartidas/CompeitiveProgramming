#include <iostream>
#include <fstream>
#include <math.h>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;

int countbits(int n){
	int count=0;
	while(n){
		count++;
		n-=n&-n;
	}
	return count;
}

struct node{
	int x,y,bitmask,dist;
	bool operator<(const node& b) const
	{
		int count1 = countbits(bitmask);
		int count2 = countbits(b.bitmask);
		if(count1==count2)
			return dist>b.dist;
		return count1>count2;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	int dx[] = {0,-1,0,1};
	int dy[] = {1,0,-1,0};
	const int MAX = 0xffffff;
	while(t-->0){
		int N;
		cin>>N;
		int map[N][N];
		bitset<MAX> visited;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cin>>map[i][j];
			}
		}
		int sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;
		node n = {sx,sy,1<<map[sx][sy],0};
		priority_queue<node> queue;
		queue.push(n);
		int apologies = 0;
		while(!queue.empty()){
			auto curr_node = queue.top();
			queue.pop();
			if(curr_node.x==ex&&curr_node.y==ey){
				apologies = countbits(curr_node.bitmask);
				break;
			}
			for(int i=0;i<4;i++){
				int nx=curr_node.x+dx[i];
				int ny=curr_node.y+dy[i];
				if(ny<N&&ny>=0&&nx<N&&nx>=0){
					node tmp = {curr_node.x+dx[i],curr_node.y+dy[i],curr_node.bitmask,curr_node.dist+1};
					tmp.bitmask|=(1<<map[nx][ny]);
					int val = (nx<<17)|(ny<<11)|tmp.bitmask;
					if(visited[val])
						continue;
					queue.push(tmp);
					visited.set(val);
				}				
			}
		}
		cout<<(apologies)<<"\n";
	}
	return 0;
}
