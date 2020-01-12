#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;
#define PI 3.14159265358979323846

ll cross(ll x1,ll y1,ll x2,ll y2,ll subx,ll suby){
	x1-=subx;
	x2-=subx;
	y1-=suby;
	y2-=suby;
	return x1*y2-x2*y1;
}
bool between(ll l, ll r, ll x){
	return (l<=x&&x<=r)||(r<=x&&x<=l);
}

int main(){
	int q;
	cin>>q;
	while(q-->0){
		ll l1[4];
		ll l2[4];
		for(int i=0;i<4;i++)
			cin>>l1[i];
		for(int i=0;i<4;i++)
			cin>>l2[i];
		ll c1 = cross(l1[2],l1[3],l2[0],l2[1],l1[0],l1[1]);
		ll c2 = cross(l1[2],l1[3],l2[2],l2[3],l1[0],l1[1]);
		
		ll c3 = cross(l2[2],l2[3],l1[0],l1[1],l2[0],l2[1]);
		ll c4 = cross(l2[2],l2[3],l1[2],l1[3],l2[0],l2[1]);
		if((c3*c4<0)&&(c1*c2<0)){
			puts("1");
			continue;
		}
		if(!c1){
			if(between(l1[0],l1[2],l2[0])&&between(l1[1],l1[3],l2[1])){
				puts("1");
				continue;
			}
		}
		if(!c2){
			if(between(l1[0],l1[2],l2[2])&&between(l1[1],l1[3],l2[3])){
				puts("1");
				continue;
			}			
		}
		if(!c3){
			if(between(l2[0],l2[2],l1[0])&&between(l2[1],l2[3],l1[1])){
				puts("1");
				continue;
			}			
		}
		if(!c4){
			if(between(l2[0],l2[2],l1[2])&&between(l2[1],l2[3],l1[3])){
				puts("1");
				continue;
			}
		}
		puts("0");
	}
	return 0;
}
