#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;

const int MAXN = 5005;
const ll MOD = 1e9+7;

string pattern;
ll count[MAXN];

struct node{
	node* ls[27];
};

node* root = new node();
int N,K;

void insert(string str){
	node* n = root;
	int ind =0;
	for(char letter:str){
		if(ind++>MAXN)
			break;
		letter-='a';
		if(!(n->ls[letter])){
			n->ls[letter] = new node();
		}
		n = n->ls[letter];
	}
	n->ls[26] = root; 
}

ll search(){
	for(int start=0;start<N;start++){
		int ind = 0;
		
		for(node* n = root;start+ind<N&&n->ls[pattern[start+ind]-'a'];ind++){
			n = n->ls[pattern[start+ind]-'a'];
			if(n->ls[26]){
				count[start+ind+1]+=count[start];
				count[start+ind+1]%=MOD;
			}
		}		
	}
	return count[N];
} 

int main(){
	cin>>pattern;
	N = pattern.length();
	cin>>K;
	for(int i=0;i<K;i++){
		string str;
		cin>>str;
		insert(str);
	}
	count[0] = 1;
	cout<<search();	
	return 0;
}
