#include <iostream>
#include <fstream>
#include <bitset>
#include <priority_queue>

using namespace std;

ifstream inFile;

const int MAX_N = 100000;

const int BASE = 11;

const int MODS[] = {1000000009,1000000007};

bitset<1000000009> set;

int locations[MAX_N][11];

int pows[MAX_N];

struct compare{

	bool operator()(int a,int b){
		return locations;
	}
}

int main(){

	inFile.open("roboherd.in");
	int n,k,i,j,tmp;
	inFile>>n>>k;
	for(i=0;i<n;i++){
		if(i==0)
			pows[i]=1;
		else
			pows[i] = pows[i-1]*BASE % ;
		inFile>>tmp;
		locations[i][0] = tmp;
		for(j=1;j<=tmp;j++)
			inFile>>locations[i][j];
	}

	
	while(){

	}
	return 0;
}
