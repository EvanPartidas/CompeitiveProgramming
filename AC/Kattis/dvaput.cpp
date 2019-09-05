#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

const int MAX_SIZE = 200001;

const int BASE = 27;

const long long mods[] = {0x7fffffff,1000000007,1000000009};

long long inv[3],pows[3][MAX_SIZE];

int len;

long long power(long long x, unsigned long long y, unsigned long long m) 
{
    if (y == 0) 
        return 1;
    long long p = power(x, y/2, m) % m; 
    p = (p * p) % m; 
  
    return (y%2 == 0)? p : (x * p) % m; 
}

bitset<0x7fffffff> set;

bool func(int k,long long str[]){
    int i,j;
    
    if(k<1)
        return false;
    
    
    long long hashes[] = {0,0,0};
    for(i=0;i<k;i++){
    	for(j=0;j<3;j++){
		hashes[j] += (str[i]*pows[j][i])%mods[j];
		hashes[j] %= mods[j];
        }
    }
    for(j=0;j<3;j++)
    	set.set(hashes[j],1);
    for(i=k;i<len;i++){
        for(j=0;j<3;j++){
		hashes[j]-=str[i-k];
		hashes[j]*=inv[j];
		hashes[j]%=mods[j];
		hashes[j]+=(str[i]*pows[j][k-1])%mods[j];
		hashes[j]%=mods[j];
        }
        bool val = true;
	for(j=0;j<3;j++)
	   val&=set[hashes[j]];
        if(val)
            return true;
	for(j=0;j<3;j++)
	   set.set(hashes[j],1);
    }
    
    return false;
}

int main() {
    int i,j;
    char c;
    
    for(i=0;i<3;i++){
	    pows[i][0] = 1;
	    pows[i][1] = BASE;
    }
    
    for(i=0;i<3;i++){
        inv[i] = power(BASE,mods[i]-2,mods[i]);
    }
    
    cin>>len;
    
    for(i=2;i<len;i++){
    	for(j=0;j<3;j++)
        	pows[j][i] = (pows[j][i-1]*BASE)%mods[j];
    }

    long long str[len];
    for(i=0;i<len;i++){
        cin>>c;
        str[i] = c-'a'+1;
    }
    
    int lo = 0,
        hi = len,mid;
    while(lo+1<hi){
        mid = (lo+hi)/2;
        if(func(mid,str))
            lo = mid;
        else
            hi = mid;
        
    }
    cout<<lo<<endl;
    
    return 0;
}
