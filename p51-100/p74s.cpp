#include<iostream>
using namespace std;

const int limit=1000001;
int have[10000006]= {0};
int fac[]= {1,1,2,6,24,120,720,5040,40320,362880};
int sum,cnt,tmp[100];
int cal(int n)
{
    if(have[n]>0) return have[n];
    cnt=0;
    while(!have[n])
    {
        have[n]=-1;
        tmp[cnt++]=n;
        sum=0;
        while(n)
        {
            sum+=fac[n%10];
            n/=10;
        }
        n=sum;
    }
    have[tmp[0]]=have[n]==-1?cnt:cnt+have[n];
    for(int i=1; i<cnt; i++)
        have[tmp[i]]=0;
    return have[tmp[0]];
}
int main()
{
    int ans=0;
    for(int i=1; i<limit; i++)
        if(cal(i)>=60)
            ans++;
    cout<<ans<<endl;
    return 0;
}


 /*while(true)
    {
        if(have[n]==0)
            have[n]=-1;
        else if(have[n]==-1)
        {
            have[tmp[0]]=cnt;
            break;
        }
        else
        {
            have[tmp[0]]=cnt+have[n];
            break;
        }
        tmp[cnt++]=n;
        sum=0;
        while(n)
        {
            sum+=fac[n%10];
            n/=10;
        }
        n=sum;
    }*/
