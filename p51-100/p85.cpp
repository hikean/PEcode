#include<iostream>
#include<time.h>
using namespace std;

const int limit=500;
long long  rect[limit][limit]={0};
int ans,delt=200;
template<typename T>
T abs(T a)
{
    return a>0?a:-a;
}
int main()
{
    int start=clock();
    for(int i=1;i<limit;i++)
        for(int j=1;j<=i;j++)
        {
            rect[j][i]=rect[i][j]=rect[i-1][j]+rect[i][j-1]-rect[i-1][j-1]+i*j;
            if(abs(rect[i][j]-2000000)<= delt)
            {
                ans=i*j;
                delt=abs(rect[i][j]-2000000);
            }
        }
    cout<<ans<<endl;
    cout<<clock()-start<<endl;
    return 0;
}
