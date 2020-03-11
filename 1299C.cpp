#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	const int MAXA = 1e6+5;
	int N;
	cin>>N;
	ll arr[N+2];
	for(int i=1;i<=N;i++){
		cin>>arr[i];
		arr[i] = MAXA - arr[i];
	}
	arr[0]=0;
	arr[N+1]=0;
	vector<int> hull;
	hull.push_back(0);
	for(int toadd=1;toadd<=N+1;toadd++){
		while(hull.size()>=2){
			int test = hull[hull.size()-1];
			int origin = hull[hull.size()-2];
			if((toadd-test)*arr[origin] < (test-origin)*arr[toadd]+(toadd-origin)*arr[test]))
				hull.pop_back();
			else
				break;
				
		}
		hull.push_back(toadd);
	}
	
	return 0;
}
