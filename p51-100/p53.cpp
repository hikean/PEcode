#include<iostream>

using namespace std;

int C[105][105]={0};
const int limit=101;
int main()
{
    for(int i=0;i<limit;i++)
        C[i][0]=C[i][i]=1;
    for(int i=1;i<limit;i++)
        for(int j=0;j<=i;j++)
        {
            C[i][j]=C[i-1][j]+C[i-1][j-1];
            if(C[i][j]>1000000)
                C[i][j]=1000001;
        }
    int ans=0;
    for(int i=1;i<limit;i++)
        for(int j=1;j<i;j++)
            if(C[i][j]>=1000000)
                ans++;
    cout<<ans<<endl;
    return 0;
}
