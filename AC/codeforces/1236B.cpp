#include <iostream>

using namespace std;

long long power(long long x, unsigned long long y, unsigned long long m) 
{
    if (y == 0) 
        return 1;
    long long p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}

int main(){
	long m = 1e9+7;
	int A,B;
	cin>>A>>B;
	cout<<(power(power(2,B,m) -1,A,m));
	return 0;
}
