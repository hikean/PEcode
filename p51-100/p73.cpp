#include<iostream>
using namespace std;

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
    const int limit=12000;
    int ans=0;
    for(int i=4;i<=limit;i++)
        for(int j=i/3;j<=(i>>1);j++)// equal or not ??????????
            if(3*j>i&&2*j<i&&gcd(i,j)==1)
                ans++;
    cout<<ans<<endl;
    return 0;
}
