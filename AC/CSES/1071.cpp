#include <iostream>

using namespace std;

typedef long long ll;

int main(){
	int N;
	cin>>N;
	while(N-->0){
		ll a,b;
		cin>>a>>b;
		if(a>b){
			if(a%2==0)
				cout<<(a*a-b+1)<<endl;
			else
				cout<<((a-1)*(a-1)+b)<<endl;
		}
		else{
			ll tmp = b;
			b = a;
			a = tmp;
			if(a%2==1)
				cout<<(a*a-b+1)<<endl;
			else
				cout<<((a-1)*(a-1)+b)<<endl;
		}
	}
	return 0;
}
