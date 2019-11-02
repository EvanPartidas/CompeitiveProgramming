#include <iostream>

using namespace std;

int sum(int n){
	int ret=0;
	while(n){
		ret += n%10;
		n/=10;
	}
	return ret;
}

int main(){
	int N,i;
	while(1){
		cin>>N;
		if(!N)
			break;
		int s = sum(N);
		for(i=11;i<=100;i++){
			if(s==sum(N*i))
				break;
		}
		cout<<i<<endl;
	}
}
