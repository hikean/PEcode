
#include<iostream>
#define MAXN 1000001
using namespace std;

int bprime[MAXN]={0};
int prime[MAXN/9];
int nprime=0;
int main()
{
    for (int i=2;i<2000;i++)
    if(!bprime[i])
        for(int j=2;i*j<=MAXN;j++)
            bprime[i*j]=1;
    for(int i=2;i<MAXN;i++)
        if(!bprime[i])
            prime[nprime++]=i;
    int ans=0,sum,len=0;
    for(int i=0;i<nprime;i++)
    {
        sum=0;
        int j;
        for(j=i;j<nprime;j++)
        {
            sum+=prime[j];
            if(sum>=MAXN) break;
            if(!bprime[sum]&&len <=j-i)
            {
                len=j-i+1;
                ans=sum;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
