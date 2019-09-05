#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

const int MAXN = 5005;
const int MAXK = 5005;
const int MAXM = 100005;
const int MOD = 1000000007;


int K,N,M;

vector<int> adj[MAXN];

vector<int> steps;

int letters[26];

long long nums[MAXK];

long long counts[MAXN];

long long dp[MAXK];

long long power(long long x, unsigned long long y, unsigned long long m) 
{
    if (y == 0) 
        return 1;
    long long p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}

int MAXC=0;

int main(){
	int i,j,k,s,c;

	char str;

	ifstream IN;
	
	ofstream OUT;

	IN.open("poetry.in");
	OUT.open("poetry.out");
	
	IN>>N>>M>>K;


	for(i=0;i<N;i++){
		IN>>s>>c;
		adj[c].push_back(s);
		MAXC=max(MAXC,c);
	}
	
	for(i=0;i<M;i++){
		IN>>str;
		letters[str-'A']++;
	}

	IN.close();
	
	dp[0]=1;
	
	for(i=0;i<=K;i++){
		for(j=0;j<=MAXC+1;j++)
			for(k=0;k<adj[j].size();k++){
				if(i+adj[j][k]>K)
					continue;
				dp[i+adj[j][k]]+=dp[i];
				dp[i+adj[j][k]]%=MOD;
				if(i+adj[j][k]==K){
					counts[j]+=dp[i];
					counts[j]%=MOD;
				}
			}
	}
	

	long long res = 1;
	long long mul = 0;
	for(i=0;i<26;i++){
	    	if(letters[i]<1)
	    	  continue;
		mul = 0;
		for(j=0;j<=MAXC;j++){
			if(letters[i]==0) continue;
			mul+=power(counts[j],letters[i],MOD);
			mul%=MOD;
		}
		if(mul>0){
			res*=mul;
			res%=MOD;
		}
	}
	OUT<<res<<endl;
	cout<<res;
	OUT.close();
	return 0;
}
