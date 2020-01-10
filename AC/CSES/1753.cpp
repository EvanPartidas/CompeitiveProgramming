#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const int MAXN = 1e6;

string str,pattern;
int n,m;
int b[MAXN];


int kmp(){
	//Preprocess pattern
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && pattern[i] != pattern[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
	i=0;j=0;
	int ret = 0;
	while(i<n){
		while(j>=0 && str[i]!=pattern[j]) j= b[j];
		i++;j++;
		if(j==m) {
			ret++;
			j = b[j];
		}
	}
	return ret;
}

int main(){
	cin>>str>>pattern;
	n = str.length();
	m = pattern.length();
	cout<<kmp();	
	return 0;
}
