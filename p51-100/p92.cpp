#include<iostream>

using namespace std;

const int limit=10000001;

bool have[limit]={0};// true for 89
int tmp[500],cnt,sum;
int square[]={0,1,4,9,16,25,36,49,64,81};
inline bool calcu(int n)
{
    cnt=0;
    if(have[n]) return true;
    while(!have[n])
    {
        if(n==1) return false;
        tmp[cnt++]=n;
        sum=0;
        while(n)
        {
            sum+=square[n%10];
            n/=10;
        }
        n=sum;
    }
    if(tmp[0]>1000) return true;
    for(int i=0;i<cnt;i++)
        have[tmp[i]]=true;
    return true;
}
int main()
{
    have[89]=true;
    int ans=0;
    for(int i=1;i<limit;i++)
        if(calcu(i)) ans++;
    cout<<ans<<endl;
    return 0;
}
