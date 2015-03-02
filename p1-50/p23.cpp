#include<iostream>
using namespace std;

const int cnt=28124;
bool is[cnt]={0};
int abundant[cnt];
int num=0;
bool isAbundant(int n)
{
    int sum=1,i;
    for (i=2;i*i<n;i++)
        if(n%i==0)
            sum+=(i+n/i);
    if(i*i==n)
        sum+=i;
    return sum>n;
}
int main()
{
    for(int i=1;i<cnt;i++)
        if(isAbundant(i))
            abundant[num++]=i;
    for(int i=0;i<num;i++)
        for(int j=i;j<num;j++)
            if(abundant[i]+abundant[j]<cnt)
                is[abundant[i]+abundant[j]]=true;
    int ans=0;
    for(int i=1;i<cnt;i++)
        if(!is[i])
            ans+=i;
    cout<<ans<<endl;
    return 0;
}
