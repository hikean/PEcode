#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int limit=1500000;
int gcd(int a,int b)
{
    return !b?a:gcd(b,a%b);
}
int Len[limit+5]= {0};
int main()
{
    int a,b,c,ans=0,sum;
    for(int m=1; m<=1224; m++)
        for(int n=1; n<m; n++)
        {
            a=m*m-n*n;///a = m^2-n^2,b = 2mn,c = m^2 + n^2
            b=2*m*n;
            c=m*m+n*n;
            sum=a+b+c;
            if(a>b) swap(a,b);
            if(sum<=limit&&gcd(c,gcd(b,a))==1)
            {
                for(int s=sum; s<=limit; s+=sum)
                    Len[s]++;
            }
        }
    for(int i=1; i<=limit; i++)
        if(Len[i]==1) ans++;
    cout<<ans<<endl;
    return 0;
}
