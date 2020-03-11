#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string str;
	cin>>str;
	int N = str.size();
	if(N==1){//Edge case
		cout<<str<<endl;
		return 0;
	}
	int POS[N*2];
	for(int i=0;i<2*N;i++)
		POS[i]=0;
	int m = 0;
	int mind = 0;
	POS[1]=1;
	int MID = 0;
	for(int cntr=2;cntr<2*N;cntr++){
		int tmplen = MID+POS[MID]>cntr?min(POS[2*MID-cntr],MID+POS[MID]-cntr):0;
		int l=(cntr-1)/2-tmplen/2;
		int r=(cntr-1)/2+(cntr%2?0:1)+tmplen/2;
		while(l>=0&&r<N&&str[l]==str[r]) l--,r++;
		l++,r--;
		POS[cntr] = r-l+1;
		if(cntr+POS[cntr]>MID+POS[MID]) MID = cntr;
		if(POS[cntr]>m){
			m = POS[cntr];
			mind = (cntr-POS[cntr])/2;
		}
	}
	cout<<str.substr(mind,m);
	
	return 0;
}
