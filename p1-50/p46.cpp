#include<iostream>
#include<math.h>
using namespace std;
const int limit=10000001;
bool bprime[limit]={0};
int prime[limit/8]={0};
int nprime=0;
bool isprime(int n)
{
   if(n<limit) return bprime[n]==false;
   int i=0;
   while(prime[i]*prime[i]<=n)
   {
       if(n%prime[i]==0) return false;
       i++;
   }
   return true;
}
bool issquare(int n)
{
    int tmp=sqrt(n);
    return tmp*tmp==n;
}
bool check(int n)
{
    for(int i=0;prime[i]<n;i++)
    {
        int tmp=n-prime[i];
        if((tmp&1)==0&&issquare(tmp>>1))
            return true;
    }
    return false;
}

int main()
{
    for(int i=2;i<1000;i++)
        if(!bprime[i])
            for(int j=i*2;j<limit;j+=i)
                bprime[j]=true;
    for(int i=2;i<limit;i++)
        if(!bprime[i])
            prime[nprime++]=i;
    for(int i=3;;i+=2)
        if(!isprime(i)&&!check(i))
        {
            cout<<i<<endl;
            return 0;
        }


    return 0;
}
