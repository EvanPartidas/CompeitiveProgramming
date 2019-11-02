#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	int N;
	cin>>N;
	double l = log(N)/log(2);
	int num = (int)pow(2,floor(l));
	int count=num==N?0:1;
	while(N){
		if(num==N)
			break;
		if(num<N){
			N-=num;
			continue;
		}
		count++;
		num>>=1;
	}
	printf("%d %d\n",(int)pow(2,ceil(l)),count);
	return 0;
}
