#include <iostream>
#include <bitset>

using namespace std;

bitset<42> set;

int main(){
	int i,count=0,num;
	for(i=0;i<10;i++){
		cin>>num;
		num%=42;
		if(!set[num])
			count++;
		set.set(num);
	}
	cout<<count<<endl;

}
