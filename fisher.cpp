#include <iostream>

using namespace std;

int MAXN = 55;

int MAXT = 1005;

int time[MAXN][MAXN];

int toll[MAXN][MAXN];

int N,T;

pair<int,int> minCost(int node,int time_left){

}

int main(){

	int i,j;

	while(1){
		cin>>N>>T;
		if(N<0)
			break;

		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				cin>>time[i][j];
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				cin>>toll[i][j];

		auto ret = minCost();
	}

	return 0;
}
