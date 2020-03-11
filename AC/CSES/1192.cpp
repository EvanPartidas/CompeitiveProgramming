#include <iostream>

using namespace std;
typedef long long ll;

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

char map[1005][1005];

int X,Y;

void fill(int x,int y){
	map[x][y]='#';
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<X&&ny>=0&&ny<Y&&map[nx][ny]=='.')
			fill(nx,ny);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>X>>Y;
	for(int i=0;i<X;i++)
		cin>>map[i];
	int count =0;
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++){
			if(map[i][j]=='.'){
				count++;
				fill(i,j);
			}
		}
	}
	cout<<count;
	return 0;
}
