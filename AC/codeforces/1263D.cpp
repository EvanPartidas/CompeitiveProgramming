#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <math.h>

using namespace std;

const int MAXN=2e5+5;

int ufds[256];

bitset<MAXN> roots;

int find(int node){
	if(ufds[node]==node){
		roots.set(node);
		return node;
	}
	return ufds[node]=find(ufds[node]);
}

void join(int a,int b){
	a = find(a);
	b = find(b);
	ufds[b]=a;
	roots.reset(b);
}

int main(){
	int n;
	cin>>n;
	string str;
	for(int i=0;i<256;i++){
		ufds[i]=i;
	}
	while(n-->0){
		cin>>str;
		int len = str.length();
		find(str[len-1]);
		for(int i=0;i<len-1;i++){
			if(find(str[i])!=find(str[i+1]))
			join(str[i],str[i+1]);
		}
	}
	cout<<roots.count();
	return 0;
}
