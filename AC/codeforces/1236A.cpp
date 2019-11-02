#include <iostream>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T-->0){
		int a,b,c;
		cin>>a>>b>>c;
		int sum =0;
		sum+=3*min(b,c/2);
		b-=min(b,c/2);
		sum+=3*min(a,b/2);
		cout<<sum<<endl;
		
	}
	return 0;
}
