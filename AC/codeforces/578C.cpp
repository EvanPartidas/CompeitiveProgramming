#include <iostream>
#include <math.h>

using namespace std;
typedef long double ld;

#define EPS 1e-7

ld mdfyKadanes(ld arr[],ld x,int N){
	ld m=0;
	ld neg=0,pos=0;
	for(int i=0;i<N;i++){
		neg-=arr[i]-x;
		pos+=arr[i]-x;
		neg = max((ld)0,neg);
		pos = max((ld)0,pos);
		m = max(m,max(neg,pos));
	}
	return m;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int N;
	cin>>N;
	ld arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];
		
	ld l = -11000;
	ld r = 11000;
	ld m = 1e20;
	ld v1=0,v2=1e8;
	while(fabs(v2-v1)>EPS||fabs(l-r)>EPS){
		ld m1 = l+(r-l)/3;
		ld m2 = r-(r-l)/3;
		v1 = mdfyKadanes(arr,m1,N);
		v2 = mdfyKadanes(arr,m2,N);
		m = min(m,min(v1,v2));
		if(v1<v2)
			r = m2;
		else
			l = m1;
	}
	
	printf("%.6Lf\n",m);
	return 0;
}
