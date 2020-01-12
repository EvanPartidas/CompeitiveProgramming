#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;
#define PI 3.14159265358979323846
int main(){
	ll sx,sy,x,y,q;
	cin>>sx>>sy>>x>>y>>q;
	x-=sx;
	y-=sy;
	ll m1 = x*x+y*y;
	for(int i=0;i<q;i++){
		ll a,b;
		cin>>a>>b;
		a-=sx;
		b-=sy;
		ll cross = x*b-y*a;
		if(cross<0){
			puts("CLOCKWISE");	
		}
		else if(cross>0){	
			puts("COUNTER_CLOCKWISE");	
		}
		else {
			ll m2 = a*a+b*b;
			auto bruh = acos((x*a+y*b)/sqrt(m2*m1));
			if(bruh==PI){
				puts("ONLINE_BACK");
			}
			else if(m1<m2){
				puts("ONLINE_FRONT");
			}
			else{
				puts("ON_SEGMENT");
			}
			
		}
	}
	return 0;
}
