#include <iostream>
#include <math.h>
using namespace std;

int a,d;
int main(){
	cin>>a>>d;
	double n = d/a;
	int mod = d%a;
	printf("%d",a+(int)ceil(mod/n));
	return 0;
}
