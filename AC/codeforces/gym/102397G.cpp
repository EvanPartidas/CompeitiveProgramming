    #include <iostream>
    #include <unordered_map>
     
    using namespace std;
    
    unordered_map<long long,long long> s1,s2;
     
    int main(){
     
    	int N,K;
    	cin>>N>>K;
    	long long c1=0,c2=0,m;
    	for(int i=0;i<N;i++){
    		cin>>m;
    		auto it = s1.find(K-m);
    		if(it!=s1.end()){
    			c1+=(*it).second;
			}
			if(s1.find(m)!=s1.end())
    			s1[m]++;
			else
				s1[m]=1;
			//printf("M: %d\t s1[m]:%d\n",m,s1[m]);
    	}
    	for(int i=0;i<N;i++){
    		cin>>m;
    		auto it = s2.find(K-m);
    		if(it!=s2.end()){
    			c2+=(*it).second;
			}
			if(s2.find(m)!=s2.end())
    			s2[m]++;
			else
				s2[m]=1;
    	}
    	//printf("%d %d\n",c1,c2);
    	if(c1>c2)
    		puts("MAHMOUD");
    	else if(c2>c1)
    		puts("BASHAR");
    	else
    		puts("DRAW");
    	return 0;
    }
