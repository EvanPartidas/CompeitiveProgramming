#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

int nums[MAXN];

int BIT[MAXN];

vector<int> ans;

int N;

void update(int index,int delta){
	while(index<=N){
		BIT[index]+=delta;
		index+=index&(-index);
	}
}

int sum(int index){
	int sum=0;
	while(index>0){
		sum+=BIT[index];
		index-=index&(-index);
	}
	return sum;
}

int main(){
	int i,k,tmp;

	ifstream IN;
	ofstream OUT;

	IN.open("sleepy.in");
	OUT.open("sleepy.out");

	IN>>N;
	for(i=0;i<N;i++){
		IN>>nums[i];
	}
	int prev=N+1;
	for(k=N-1;k>=0;k--){
		if(nums[k]>=prev)
			break;
		update(nums[k],1);
		prev = nums[k];
	}
	k++;
	for(i=0;i<k;i++){
		tmp = sum(nums[i])+k-i-1;
		//cout<<tmp-k+i+1<<endl;
		update(nums[i],1);
		ans.push_back(tmp);
	}

	OUT<<ans.size()<<endl;
	//cout<<ans.size()<<endl;
	for(i=0;i<ans.size()-1;i++){
		OUT<<ans[i]<<" ";
		//cout<<ans[i]<<" ";
	}
	OUT<<ans[i];
	//cout<<ans[i];
	return 0;
}
