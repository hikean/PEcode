#include<iostream>
#include<stdio.h>
using namespace std;

const long long limit=10000000;
bool bprime[limit]={0};
int prime[limit/10],nprime=0;
bool inline isprime(long long  n)
{
    if(n<limit) return bprime[n]==false;
    for(long long i=0;prime[i]*prime[i]<=n;i++)
        if(n%prime[i]==0) return false;
    return true;
}

long long tmp;
int main()
{
    for(int i=2;i<10000;i++)
        if(!bprime[i])
            for(int j=i<<1;j<limit;j+=i)
                bprime[j]=true;
    for(int i=2;i<limit;i++)
        if(!bprime[i])
            prime[nprime++]=i;
    int all=5,ok=3;
    long long i;
    for(i=2;;i++)
    {
        tmp=(i*2+1)*(i*2+1);
        if(isprime(tmp-i*2)) ok++;
        if(isprime(tmp-i*4)) ok++;
        if(isprime(tmp-i*6)) ok++;
        all+=4;
        if(ok*10<all)
        {
            cout<<(i*2+1)<<endl;
            break;
        }
    }
    return 0;
}
