#include <iostream>
#include <math.h>
typedef long long ll;
using namespace std;
#define PI 3.14159265358979323846
#define EPS 0.000000001

struct point {double x,y; point(){x=0;y=0;} point(double _x,double _y): x(_x), y(_y){}};
struct line {double a,b,c;};

void pointsToLine(point p1,point p2,line &l){
	if(fabs(p1.x-p2.x)<EPS){
		l.a=1;l.b=0;l.c=-p1.x;
	}else{
		l.a = -(p1.y-p2.y)/(p1.x-p2.x);
		l.b = 1;
		l.c = -l.a*p1.x - p1.y;
	}
}

bool areParallel(line l1, line l2){
	return (fabs(l1.a-l2.a)<EPS)&&(fabs(l1.b-l2.b)<EPS);
}

bool arePerpendicular(line l1,line l2){
	if(l1.b == 0){
		return l2.a==0;
	}
	if(l2.b == 0){
		return l1.a==0;
	}
	return fabs(l2.a+1/l1.a)<EPS;
}

int main(){
	int q;
	cin>>q;
	while(q-->0){
		line l1;
		line l2;
		double tmp[4];
		for(int i=0;i<4;i++){
			cin>>tmp[i];
			pointsToLine(point(tmp[0],tmp[1]),point(tmp[2],tmp[3]),l1);
		}
		for(int i=0;i<4;i++){
			cin>>tmp[i];
			pointsToLine(point(tmp[0],tmp[1]),point(tmp[2],tmp[3]),l2);
		}
		if(areParallel(l1,l2)){
			cout<<2<<endl;
		}else if(arePerpendicular(l1,l2)){
			cout<<1<<endl;
		}
		else
			cout<<0<<endl;
	}
	return 0;
}
