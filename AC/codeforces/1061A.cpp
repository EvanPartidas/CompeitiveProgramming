#include <iostream>

using namespace std;

int main(){

	int S,N;
	cin>>N>>S;
	cout<<(S/N + ((S%N==0)?0:1));
	return 0;
}
