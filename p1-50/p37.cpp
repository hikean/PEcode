#include<iostream>
#define MAXN 1000001
using namespace std;

bool bprime[MAXN]={0};
bool check(int n)
{
    int digit[11]={0},cnt=0;
    while(n)
    {
        if(bprime[n]) return false;
        digit[cnt++]=n%10;
        n/=10;

    }
    int base=1;
    for(int i=0;i<cnt;i++)
    {
        n=n+digit[i]*base;
        base*=10;
        if(bprime[n]) return false;
    }
    return true;
}
int main()
{
    bprime[0]=bprime[1]=true;
    for (int i=2;i<10000;i++)
    if(!bprime[i])
        for(int j=2*i;j<=MAXN;j+=i)
            bprime[j]=true;
    long long  ans=0;
    int cnt=0;
    for(int i=11;i<MAXN&&cnt<11;i++)
        if(!bprime[i]&&check(i))
        {
            ans+=i;
            cnt++;

        }
    cout<<ans<<endl;
    return 0;
}
