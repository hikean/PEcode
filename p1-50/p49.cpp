#include<iostream>
#include<algorithm>
#define MAXN 2000001
using namespace std;

int bprime[MAXN]= {0};

bool check(int a,int b,int c)
{
    int digit[4];
    for(int i=0; i<4; i++)
    {
        digit[i]=a%10;
        a/=10;
    }
    int bok=0,cok=0;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            if(i==j) continue;
            for (int k=0; k<4; k++)
            {
                if(i==k||j==k) continue;
                for(int t=0; t<4; t++)
                {
                    if(t==i||t==j||t==k) continue;
                    int tmp=digit[i]*1000+digit[j]*100+digit[k]*10+digit[t];
                    if(tmp==b) bok++;
                    if(tmp==c) cok++;
                }
            }
        }
    return (cok&&bok);
}
int prime[MAXN/9];
int nprime=0;

int main()
{
    for (int i=2; i<2000; i++)
        if(!bprime[i])
            for(int j=2; i*j<=MAXN; j++)
                bprime[i*j]=1;
    for(int i=1000; i<9999; i++)
        if(!bprime[i])
            prime[nprime++]=i;
    for(int i=0; i<nprime; i++)
        for(int j=i+1; j<nprime; j++)
            if(!bprime[prime[j]*2-prime[i]]&&check(prime[i],prime[j],prime[j]*2-prime[i]))
                cout<<"Bingo "<<prime[i]<<" "<<prime[j]<<" "<<prime[j]*2-prime[i]<<endl;
    return 0;
}
