#include <iostream>

using namespace std;

int main(){
	int T;
	cin>>T;
	while(T-->0){
		int N;
		cin>>N;
		N--;
		unsigned long long three = N-(N%3);
		unsigned long long five = N-(N%5);
		unsigned long long fifteen = N-(N%15);
		three/=3;
		five/=5;
		fifteen/=15;
		three = 3*(three)*(three+1)/2;
		five = 5*(five)*(five+1)/2;
		fifteen = 15*(fifteen)*(fifteen+1)/2;
		cout<<(three+five-fifteen)<<endl;
	}
}
