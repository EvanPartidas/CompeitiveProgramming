#include <iostream>

using namespace std;

const int MAXN = 1005;
const int MOD = 1e9+7;

int dp[MAXN][MAXN];
char map[MAXN][MAXN];

int N;

int main(){

	cin>>N;
	for(int i=0;i<N;i++){
		cin>>map[i];		
	}
	dp[0][0]=(map[0][0]=='.');
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]=='.'){
				if(i>0&&map[i-1][j]=='.'){
					dp[i][j]+=dp[i-1][j];
					dp[i][j]%=MOD;
				}
				if(j>0&&map[i][j-1]=='.'){
					dp[i][j]+=dp[i][j-1];
					dp[i][j]%=MOD;
				}
			}
		}
	}
	cout<<dp[N-1][N-1];
	return 0;
}
