#include<iostream>

using namespace std;
const int limit=1000001;

bool bprime[limit]={0};
int prime[limit/8]={0};
int nprime=0;
bool check(int n)
{
    int i=0,cnt=0;
    if(n<limit && !bprime[n]) return false;
    while(prime[i]*prime[i]<=n)
    {
        if(n%prime[i]==0)
        {
            ++cnt;
            while(n%prime[i]==0) n/=prime[i];

            if(cnt>4)
                return false;
        }
        i++;
    }
    if(n!=1) ++cnt;
    return cnt==4;
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
    int n=2;
    int ans=0;
    while(true)
    {
        int oldn=n;
        while(check(n))
            n++;
        if(n-oldn>=4)
        {
            cout<<oldn<<endl;
            return 0;
        }
        n++;

    }
    return 0;
}
