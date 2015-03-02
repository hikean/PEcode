#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int cnt=0;
const int limit=100;
int mul[limit+5]={0};
int tmp[limit+5]={0};
#define mod 1000000

int prime[limit+5];

bool isprime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
int main()
{
    mul[0]=1;
    cnt=0;
    for(int i=2;i<limit;i++)
        if(isprime(i))
              prime[cnt++]=i;
    for(int i=0;i<cnt;i++)
    {
        for(int a=0;a<=limit;a++)
            tmp[a]=0;
        for(int j=0;j<=limit;j+=prime[i])//j power
        {
            for(int k=0;k<=limit;k++)//k power
                if(k+j>limit)
                    break;
                else
                {
                    tmp[k+j]+=mul[k];
                    //tmp[k+j]%=mod;
                }

        }
        copy(tmp,tmp+limit,mul);
    }
    for(int i=2;i<limit;i++)
        if(mul[i]>=5000)
    {
        cout<<i<<" "<<mul[i]<<" ";
        //cout<<mul[i]<<" ";
        break;
    }
    return 0;
}
