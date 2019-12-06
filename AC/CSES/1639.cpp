#include <iostream>
#include <string.h>

using namespace std;
string str1;
string str2;

int dp[5005][5005];
bool visit[5005][5005];

int help(int ind1,int ind2){
	if(ind1<0||ind2<0){
		return max(ind1,ind2)+1;
	}
	if(visit[ind1][ind2])
		return dp[ind1][ind2];
	int ret = 2e9;
	if(str1[ind1]==str2[ind2])
		 ret = min(ret,help(ind1-1,ind2-1));
	ret = min(ret,1+help(ind1-1,ind2-1));//Replace
	ret = min(ret,1+help(ind1-1,ind2));//Remove
	ret = min(ret,1+help(ind1,ind2-1));//Add
	visit[ind1][ind2] = 1;
	return dp[ind1][ind2]=ret;
}

int main(){
	cin>>str1>>str2;
	cout<<help(str1.length()-1,str2.length()-1);
	return 0;
}
