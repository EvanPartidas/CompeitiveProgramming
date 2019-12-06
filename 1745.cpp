#include <iostream>
#include <set>

using namespace std;


int arr[105];

set<int> nums;
short dp[100005][105];

int N;

bool possible(int num,int used){
	if(num==0)
		return true;
	if(num<0)
		return false;
	if(dp[num][used]>0)
		return dp[num][used]>1;
	for(int i=used;i<N;i++)
		if(possible(num-arr[i],i+1)){
			nums.insert(num);
			dp[num][used]=2;
			return true;
		}
	dp[num][used]=1;
	return false;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	int sum = 1;
	for(int i=0;i<N;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	while(sum-->0){
		possible(sum,0);
	}
	cout<<nums.size()<<endl;
	for(int n:nums)
		cout<<n<<" ";
		
	return 0;
}
