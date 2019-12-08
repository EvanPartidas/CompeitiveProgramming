#include <iostream>
#include <algorithm>
using namespace std;



int main(){
	int t,nums[3];
	cin>>t;
	while(t-->0){
		cin>>nums[0]>>nums[1]>>nums[2];
		sort(nums,nums+3);
		int sum = 0;
		if(nums[2]>nums[1]){
			int diff = min(nums[2]-nums[1],nums[0]);
			sum+=diff;
			nums[0]-=diff;
			nums[2]-=diff;
			
		}
		if(nums[0]>1){
			sum+=nums[0];
			nums[2]-=(nums[0]+1)/2;
			nums[1]-=nums[0]/2;
		}
		sum+=min(nums[2],nums[1]);
		cout<<sum<<endl;
	}
	return 0;
}
