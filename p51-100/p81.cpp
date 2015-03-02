#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef long double LD;

const int MAXN=102;
const int INF= 1e9;

int m,n,T;
int data[MAXN][MAXN],dp[MAXN][MAXN],dpp[MAXN][MAXN];

int getN()
{
    char tmp;
    int n=0;
    do
    {
        tmp=getchar();
        if(tmp>='0'&&tmp<='9')
            n=n*10+int(tmp-'0');
    }while(tmp>='0'&&tmp<='9');
    //cout<<n<<" ";

    return n;
}

int main()
{
    freopen("p81in.txt","r",stdin);
    m=n=80;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
        {
            //scanf("%d",&data[i][j]);
            data[i][j]=getN();
            dp[i][j]=INF;
        }
    dp[0][0]=dpp[0][0]=data[0][0];       //init
    for(int i=1; i<m; i++) //init
        dp[i][0]=dpp[i][0]=dp[i-1][0]+data[i][0]; //init
    for(int j=1; j<n; j++)
    {
        for(int i=0; i<m; i++) //right
            dp[i][j]=dpp[i][j]=min(dp[i][j-1]+data[i][j],dp[i][j]);
        for(int i=1; i<m; i++) //down
            dp[i][j]=min(dp[i][j],dp[i-1][j]+data[i][j]);
        //for(int i=m-2; i>=0; i--) //up
          //  dpp[i][j]=min(dpp[i][j],dpp[i+1][j]+data[i][j]);
        for(int i=0; i<m; i++) //comebine
            dp[i][j]=dpp[i][j]=min(dp[i][j],dpp[i][j]);
    }
    printf("Answer: %d",dp[n-1][n-1]);
    return 0;
}


/**

131 673 234 103 18
201 96 342 965 150
630 803 746 422 111
537 699 497 121 965
805 732 524 37 331
**/
