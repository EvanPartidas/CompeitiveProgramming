#include <iostream>

using namespace std;

const int MAXN = 505;
const int OFFSET = 250*499;
const int MAXSUM = 2*OFFSET+5;
const int MOD = 1e9+7;

bool visited[MAXN][MAXSUM];
int dp[MAXN][MAXSUM];

int help(int num,int left){
	if(num==0&&left==0)
		return 1;
	if(num==0||left<0)
		return 0;
	if(visited[num][left])
		return dp[num][left];
	dp[num][left]=help(num-1,left+num)+help(num-1,left-num);
	dp[num][left]%=MOD;
	visited[num][left]=1;
	return dp[num][left];
}

int main(){
	int N;
	//cin>>N;
	//cout<<(help(N,OFFSET)/2);
	for(int i=1;i<=500;i++){
		if(help(i,0))
			printf("%d %d\n",i,help(i,0));
	}
	return 0;
}
