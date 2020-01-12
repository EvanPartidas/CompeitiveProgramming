#include <iostream>
#include <math.h>
typedef long long ll;
typedef long double dl;
using namespace std;
#define PI 3.14159265358979323846
#define EPS 0.000000001

struct point {dl x,y; point(){x=0;y=0;} point(dl _x,dl _y): x(_x), y(_y){}};
struct line {dl a,b,c;};

void pointsToLine(point p1,point p2,line &l){
	if(fabs(p1.x-p2.x)<EPS){
		l.a=1;l.b=0;l.c=-p1.x;
	}else{
		l.a = -(p1.y-p2.y)/(p1.x-p2.x);
		l.b = 1;
		l.c = -l.a*p1.x - p1.y;
	}
}

int main(){
	int q;
	cin>>q;
	while(q-->0){
		line l1;
		line l2;
		dl tmp[4];
		point arr[4];
		for(int i=0;i<4;i++){
			cin>>tmp[i];
		}
		arr[0] = point(tmp[0],tmp[1]);
		arr[1] = point(tmp[2],tmp[3]);
		pointsToLine(arr[0],arr[1],l1);
		for(int i=0;i<4;i++){
			cin>>tmp[i];
		}
		arr[2] = point(tmp[0],tmp[1]);
		arr[3] = point(tmp[2],tmp[3]);
		pointsToLine(arr[2],arr[3],l2);
		if(fabs(l1.b)<EPS){
			dl x = -l1.c;
			dl y = -(l2.c+l2.a*x);
			printf("%0.10Lf %0.10Lf\n",x+0,y+0);
		}
		else if(fabs(l2.b)<EPS){
			dl x = -l2.c;
			dl y = -(l1.c+l1.a*x);
			printf("%0.10Lf %0.10Lf\n",x+0,y+0);
		}
		else{
			dl x = (l2.c - l1.c)/(l1.a - l2.a);
			dl y = -l1.c-l1.a*x;
			printf("%0.10Lf %0.10Lf\n",x+0,y+0);
		}
	}
	return 0;
}
