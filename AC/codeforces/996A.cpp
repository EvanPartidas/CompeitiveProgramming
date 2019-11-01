#include <iostream>

using namespace std;

int main(){

	int N;
	cin>>N;
	cout<<(N/100 + (N%100)/20 + (N%20)/10 + (N%10)/5 + N%5);
	return 0;
}
