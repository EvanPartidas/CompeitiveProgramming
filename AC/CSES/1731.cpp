#include <iostream>

using namespace std;
typedef long long ll;

const int MAXN = 5005;
const ll MOD = 1e9+7;

string pattern;
ll count[MAXN];//This will serve as a dp array, accumulating results

struct node{//Node structure for my minimalist trie
	node* ls[27];//Array slot 26 is a terminator marker
};

node* root = new node();//Root node for my suffix trie
int N,K;

void insert(string str){//Insertion into trie
	node* n = root;
	int ind =0;
	for(char letter:str){
		if(ind++>MAXN)//Saving space (and time)
			break;
		letter-='a';
		if(!(n->ls[letter])){
			n->ls[letter] = new node();
		}
		n = n->ls[letter];
	}
	n->ls[26] = root;//Set terminator equal to root (No reason other than saving space)
}

/**
One way to visualize this is: for every letter i in the main word
we want to figure out every (further) spot in the word you can
get to. First we start with i as 0 and then go up to the last letter
in the word, this pattern means that we will have every i before us 
(and our current spot) computed already. We can simply keep track of 
how many ways there are to get to any index as we go.
*/
ll search(){//O(N^2)
	for(int start=0;start<N;start++){//Run for every suffix of the main word.
		int ind = 0;
		
		for(node* n = root;start+ind<N&&n->ls[pattern[start+ind]-'a'];ind++){
			n = n->ls[pattern[start+ind]-'a'];
			if(n->ls[26]){//Check if there is a terminator at this location
				count[start+ind+1]+=count[start];//Add in this path
				count[start+ind+1]%=MOD;
			}
		}		
	}
	return count[N];
} 

int main(){//Total: O(N^2+K)
	cin>>pattern;
	N = pattern.length();
	cin>>K;
	for(int i=0;i<K;i++){//This is O(K)
		string str;
		cin>>str;
		insert(str);//Insert every word into the suffix trie
	}
	count[0] = 1;
	cout<<search();
	return 0;
}
