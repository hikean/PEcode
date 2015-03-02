#include<iostream>

using namespace std;

int euler(int n)
{
    long long  ans=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans=ans*(i-1)/i;
            while(n%i==0) n/=i;
        }
    }
    if(n!=1)
        ans=ans*(n-1)/n;
    return ans;
}

int main()
{
    double p=0,tmp;
    int ans=0;
    for(int i=2;i<1000001;i++)
    {
        tmp=i*1.0/(euler(i)*1.0);
        if(p<tmp)
        {
            p=tmp;
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
