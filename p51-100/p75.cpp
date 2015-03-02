
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

const int maxn=1500000;
int data[maxn+5]= {0};
int fac[7],num[7],cnt;
bool bprime[maxn+5];
int prime[2000],nprime=0;
inline bool depart(int n)
{
    int oldn=n;
    for(int i=0; i<7; i++)
        fac[i]=num[i]=0;
    cnt=0;
    if(!bprime[n]) return false;
    for(int i=0;prime[i]*prime[i]<=n;i++)
    {
        if(!bprime[n])
        {
            fac[cnt++]=n;
            num[cnt-1]=1;
            return 0    ;
        }
        if(n%prime[i]==0)
        {
            fac[cnt++]=prime[i];
            num[cnt-1]=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                num[cnt-1]++;
            }
        }
    }
    for(int i=0;i<cnt;i++)
        if(fac[i]*fac[i]<oldn)
        num[i]<<=1;
    return true;
}

void dfs()
{

}

int main()
{
    bprime[0]=bprime[1]=true;
    for(int i=2; i<1300; i++)
        if(!bprime[i])
            for(int j=i<<1; j<=maxn; j+=i)
                bprime[j]=true;
    for(int i=2; i<1300; i++)
        if(!bprime[i])
            prime[nprime++]=i;
    depart(123212);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<fac[i]<<endl;
    //double pro=sqrt(.5);
    //0.488901 0.414214   0.5  0.40  0.4142
    //0.488372 0.29289321   0.5  0.28  0.29
    /**                         0        0.29289321

    a^2 + b^2 = 1 and a > b  a+b > 1 a > aqrt(.5)

    **/

    return 0;
}

/**
a<b<c
a*a=(c-b)*(c+b)
a*a=e*f
e<f
c=(e+f)/2
b=(f-e)/2
(f-e)/2> a
f-e > 2a

**/
