#include <iostream>

using namespace std;



int main(){
	int N,c,sum;
	cin>>N;
	while(N-->0){
		cin>>c>>sum;
		int num = sum/c;
		int comp = sum%c;
		int ret = 0;
		for(int i=0;i<c-comp;i++)
			ret+=num*num;
		for(int i=0;i<comp;i++)
			ret+=(num+1)*(num+1);
		cout<<ret<<endl;
	}
	return 0;
}
