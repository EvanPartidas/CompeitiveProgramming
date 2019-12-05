#include <iostream>
 
using namespace std;
 
const int MAXN = 1e5+5;
const int MAXM = 105;
const int MOD = 1e9+7;
const int ZERO = -2e9;
 
long long dp[MAXN][MAXM];
int arr[MAXN];
 
int N,M;

int bruh = 0;
int count(int index,int val){
	if(index==N-1){
		if(arr[index]==0){
			if(val>0&&val<=M)
				return dp[index][val]=1;
			else{
				dp[index][val]=ZERO;
				return 0;
			}
		}
		else
			return val==arr[index];
	}
	if(val<1 || val>M || (arr[index]!=0 && arr[index]!=val)){
		dp[index][val] = ZERO;
		return 0;
	}
	if(dp[index][val]==ZERO)
		return 0;
	if(dp[index][val])
		return dp[index][val];
	bruh++;
	cout<<"Recursive calls"<<bruh<<endl;
	std::cout.flush();
	for(int k=max(0,val-1);k<=min(M,val+1);k++){
		dp[index][val]=count(index+1,k);
		dp[index][val]%=MOD;
	}
	if(dp[index][val]==0){
		dp[index][val]=ZERO;
		return 0;
	}
	return dp[index][val];
}
 
int main(){
 
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>arr[i];		
	}
	if(arr[0]==0){
		int sum = 0;
		for(int i=1;i<=M;i++){
			sum+=count(0,i);
			sum%=MOD;
		}
		cout<<sum;
	}
	else{
		cout<<count(0,arr[0]);
	}
	return 0;
}
