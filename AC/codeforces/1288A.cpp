#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T-->0){
		int n,d;
		cin>>n>>d;
		int l = 0;
		int r = d+1;
		while(l<=r){
			int m1 = l+(r-l)/3;
			int m2 = r-(r-l)/3;
			int v1 = m1+(d+m1)/(m1+1);
			int v2 = m2+(d+m2)/(m2+1);
			if(v1<=n||v2<=n){
				puts("YES");
				goto fin;
			}
			if(v1==v2)break;
			
			if(v1<v2)
				r = m2-1;
			else
				l = m1+1;
		}
		for(int i=max(l,0);i<=r;i++){
			int v = i+(d+i)/(i+1);
			if(v<=n){
				puts("YES");
				goto fin;
			}
		}
		puts("NO");
		fin:
		continue;
	}
	
	return 0;
}
