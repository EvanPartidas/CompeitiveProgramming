#include <iostream>
#include <bitset>

using namespace std;

const int MAXN = 505;
const int OFFSET = 250*499;
const int MAXSUM = 2*OFFSET+5;
const int MOD = 1e9+7;

bool visited[MAXN][MAXSUM];
int dp[MAXN][MAXSUM];

int help(int num,int left){
	if(num==0)
		return left==OFFSET;
	if(visited[num][left])
		return dp[num][left];
	dp[num][left]=help(num-1,left+num)+help(num-1,left-num);
	dp[num][left]%=MOD;
	visited[num][left]=1;
	return dp[num][left];
}

int main(){
	int N;
	cin>>N;
	cout<<(((long long)(help(N,OFFSET))*500000004)%MOD);
	return 0;
}
