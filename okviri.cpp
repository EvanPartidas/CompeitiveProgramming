#include <iostream>
#include <string>

using namespace std;

int line1(string str){
	int i,len = str.size();
	for(i=0;i<len;i++){
		if((i+1)%3==0)
		cout<<"..*.";
		else
		cout<<"..#.";
	}
	cout<<"."<<endl;
}
int line2(string str){
        int i,len = str.size();
        for(i=0;i<len;i++){
                if((i+1)%3==0)
                cout<<".*.*";
                else
                cout<<".#.#";
        }
        cout<<"."<<endl;
}
int line3(string str){
        int i,len = str.size();
        for(i=0;i<len;i++){
                if((i+1)%3==0||(i!=0&&i%3==0))
                cout<<"*."<<str[i]<<".";
                else
                cout<<"#."<<str[i]<<".";
        }
	if(i%3==0)
        cout<<"*"<<endl;
	else
	cout<<"#"<<endl;
}



int main(){
	string str;
	getline(cin,str);
	line1(str);
	line2(str);
	line3(str);
	line2(str);
	line1(str);
	return 0;
}
