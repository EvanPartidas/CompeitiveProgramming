#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T-->0){
		int N;
		cin>>N;
		int odds = 0;
		int odd1 = 0;
		bool bruh = false;
		for(int i=1;i<=N;i++){
			int a;
			cin>>a;
			if(a%2&&!bruh){
				odds+=a;
				if(odds%2==0){
					cout<<2<<endl<<odd1<<" "<<i<<endl;
					bruh=1;
				}
				odd1 = i;
			}
			else if(!bruh){
				cout<<1<<endl<<i<<endl;
				bruh=1;
			}
		}
		if(!bruh)
			cout<<-1<<endl;
	}
	return 0;
}
