#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){

	char str[50];
	
	fgets(str,50,stdin);
	
	int pos = 1;
	
	int len = strlen(str);
	
	for(int i=0;i<len;i++){
		switch(str[i]){
			case 'A':
			if(pos==1)
				pos=2;
			else if(pos==2)
				pos=1;
			break;
			
			case 'B':
			if(pos==2)
				pos=3;
			else if(pos==3)
				pos=2;
			break;

			case 'C':
			if(pos==1)
				pos=3;
			else if(pos==3)
				pos=1;
			break;
		}
	}
	cout<<pos<<endl;
	return 0;
}
