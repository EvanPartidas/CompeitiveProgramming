#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 2e5;

int apts[MAXN],apps[MAXN];

int main(){
	int N,M,K,i,j,count;
	cin>>N>>M>>K;
	for(i=0;i<N;i++)
		cin>>apps[i];
	for(i=0;i<M;i++)
		cin>>apts[i];
	sort(apps,apps+N);
	sort(apts,apts+M);
	i=0;
	j=0;
	count=0;
	while(j<M&&i<N){
		if(abs(apps[i]-apts[j])<=K){
			i++;
			j++;
			count++;
		}
		else if(apps[i]>apts[j])
			j++;
		else
			i++;
	}
	cout<<count<<endl;
	return 0;
}
