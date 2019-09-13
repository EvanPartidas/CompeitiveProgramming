#include <iostream>

using namespace std;

int dp[201][201][201];

int list[200];

int n;

const int INF = 10000;

int recursion(int cur,int b, int w){
    if(cur>=n)
        return 0;
    if(dp[cur+1][b+1][w+1]>=0)
        return dp[cur+1][b+1][w+1];
    int m = INF;
    if(b<0||list[b]<list[cur])
        m = min(m,recursion(cur+1,cur,w));
    if(w<0||list[w]>list[cur])
        m = min(m,recursion(cur+1,b,cur));
    m = min(m,1+recursion(cur+1,b,w));
    dp[cur+1][b+1][w+1]=m;
    return m;
}

int main() {
    int i,j,k;
    while(true){
        cin>>n;
        if(n<0)
            break;
        for(i=0;i<n;i++)
            cin>>list[i];
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                for(k=0;k<=n;k++)
                    dp[i][j][k]=-1;

        cout<<recursion(0,-1,-1)<<endl;
    }
}
