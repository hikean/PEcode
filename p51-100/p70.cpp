
#include<iostream>

using namespace std;

const int limit=10000000;
bool bprime[limit]={0};
long long prime[limit/10],nprime=0;
double p=100;
int ans=12;
int cnt=0;
void inline check(int m,int n)
{
    if(double(m)/double(n)> p) return;
    int a[10]={0},b[10]={0},c=m,d=n;
    while(m)
    {
        a[m%10]++;
        m/=10;
    }
    while(n)
    {
        b[n%10]++;
        n/=10;
    }
    for(int i=0;i<10;i++)
        if(a[i]!=b[i]) return ;
    p=double(c)/double(d);
    ans=c;
}

int main()
{
    for(int i=2;i<4000;i++)
        if(!bprime[i])
            for(int j=i<<1;j<limit;j+=i)
                bprime[j]=true;
    for(int i=2;i<limit;i++)
        if(!bprime[i])
            prime[nprime++]=i;
    for(int i=0;i<nprime;i++)
        for(int j=i;prime[i]*prime[j]<=limit;j++)
            check(prime[i]*prime[j],(prime[i]-1)*(prime[j]-1));
    cout<<ans<<endl;
    return 0;
}
