#include <iostream>
#include <string>
#include <math.h>
     
using namespace std;
typedef long long ll;
     
const int MAXN = 2e5;
     
int N,M,block_size;
     
int nums[MAXN],dest[MAXN],jumps[MAXN],last[MAXN];
     
void update_block(int start){
	start = block_size*(start/block_size);
    for(int i=block_size-1;i>=0;i--){
    	int index = start+i;
    	dest[index] = index+nums[index];
    	if((dest[index]-start<block_size)&&(dest[index]<N)){
    		jumps[index] = 1+jumps[dest[index]];
    		last[index] = last[dest[index]];
    		dest[index] = dest[dest[index]];
    	}else{
    		jumps[index]=1;
    		last[index] = index;
    	}
    }
}
     
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>N>>M;
    block_size = sqrt(N);
    for(int i=0;i<N;i++)
    	cin>>nums[i];
    
    for(int start=0;start<N;start+=block_size){
    	update_block(start);
    }
    for(int i=0;i<M;i++){
    	int code,a,b;
    	cin>>code>>a;
    	a--;
    	if(!code){
    		cin>>b;
    		nums[a]=b;
    		update_block(a);
    	}
    	else{
    		int j=0;
    		while(dest[a]<N){
    			j += jumps[a];
    			a = dest[a];
    		}
    		j+=jumps[a];
    		a = last[a]+1;
    		cout<<a<<" "<<j<<"\n";
    	}
    	
    }
    
    return 0;
}
