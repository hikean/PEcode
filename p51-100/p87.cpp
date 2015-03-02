#include<iostream>
#include<set>

using namespace std;
const int limit=50000000;
int prime[10000],nprime=0;
bool have[limit+1]={0};

int main()
{
    for(int i=2; i<10000; i++)
    {
        bool f=true;
        for(int j=2; j*j<=i; j++)
            if(i%j==0)
            {
                f=false;
                break;
            }
        if(f)
            prime[nprime++]=i;
    }
    for(int i=0; prime[i]<=7071; i++)
        for(int j=0; prime[j]<=386; j++)
            for(int k=0; prime[k]<=84; k++)
            {
                int tmp=prime[i]*prime[i]+prime[j]*prime[j]*prime[j]+prime[k]*prime[k]*prime[k]*prime[k];
                if(tmp<=50000000)
                   have[tmp]=true;
            }
    int ans=0;
    for(int i=1;i<=limit;i++)
        if(have[i]) ans++;
    cout<<ans<<endl;
    return 0;
}
