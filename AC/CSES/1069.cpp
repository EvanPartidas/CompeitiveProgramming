#include <iostream>

using namespace std;

int main(){
	string str;
	cin>>str;
	int count = 0;
	int m = 0;
	for(int i=1;i<str.length();i++){
		if(str[i]==str[i-1])
			count++;
		else
			count=0;
		m  = max(m,count);
	}
	cout<<(m+1);
	return 0;
}
