#include <iostream>

using namespace std;

const int MAXM = 45;
const int MAXSUM = 1005;
const int INF = 1e9;
const int INF2 = 2e9;
int dp[MAXM][MAXSUM];
int seq[MAXM];
char out[MAXM][MAXSUM];
char str[MAXM];
int N,M;

int calc(int pos,int sum){
	if(sum<0)
		return INF2;
	if(pos>=M)
		return sum==0?0:INF2;

	if(dp[pos][sum]!=INF)
		return dp[pos][sum];
	int u = calc(pos+1,sum+seq[pos]);
	out[pos][sum] = 'U';
	int d = calc(pos+1,sum-seq[pos]);
	int m=u;
	if(d<u){
		out[pos][sum]='D';
		m=d;
	}
	return dp[pos][sum]= max(sum,m);
}
void fillstr(int pos,int sum){
	if(pos==M){
		str[M]=0;
		return;
	}
	str[pos]=out[pos][sum];
	if(out[pos][sum]=='U')
		fillstr(pos+1,sum+seq[pos]);
	else
		fillstr(pos+1,sum-seq[pos]);	
}

int main(){
	cin>>N;
	while(N-->0){
		cin>>M;
		int sum = 0;
		for(int i=0;i<M;i++){
			cin>>seq[i];
			sum+=seq[i];
		}
		for(int i=0;i<M;i++)
			for(int j=0;j<sum;j++)
				dp[i][j]=INF;
		calc(0,0);
		if(dp[0][0]<INF){
			fillstr(0,0);			 
			cout<<str<<endl;
		}
		else
			puts("IMPOSSIBLE");
	}
	
	return 0;
}
