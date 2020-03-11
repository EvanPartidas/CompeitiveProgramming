#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int N;
	cin>>N;
	ll left=0,right=0;
	ll ans=0;
	ll bruh=0;
	ll add=0;
	for(int i=0;i<N;i++){
		char c;
		cin>>c;
		if(c=='('){
			left++;
			if(right>left){
				add++;
			}
			else if(right==left){
				add++;
				ans+=add;
				add=0;
			}
			else{
				bruh++;
			}
				
		}
		else{
			right++;
			if(left<right)
				add++;
			else
				bruh--;
		}
	}
	if(left!=right)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	
	return 0;
}
