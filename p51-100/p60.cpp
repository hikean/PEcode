#include<iostream>
#include<stdio.h>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

const int limit=100000001;
bool bprime[limit]= {0};
int prime[11010],nprime=0;
struct Edge
{
    int x,y;
    bool operator < (const Edge & b) const
    {
        return this->x < b.x;
    }
    Edge(int a=0,int b=0):x(a),y(b) {}
} data[40000];
int cnt=0;
int check(int a,int b,int c,int d,int e)
{
    int num[5]= {a,b,c,d,e};
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
        {
            if(i==j) continue;
            int tmp=num[i];
            int ans=num[j];
            while(tmp)
            {
                ans*=10;
                tmp/=10;
            }
            ans+=num[i];
            if (ans>=limit||bprime[ans]) return false;
        }
    return true;
}

bool bingo(int ary[],int n)
{
    int a=0;
    for(int b=a+1; b<n; b++)
        for(int c=b+1; c<n; c++)
            for(int d=c+1; d<n; d++)
                for(int e=d+1; e<n; e++)
                    if(check(ary[a],ary[b],ary[c],ary[d],ary[e]))
                    {
                        cout<<ary[a]<<" "<<ary[b]<<" "<<ary[c]<<" "<<ary[d]<<" "<<ary[e]<<endl;
                        cout<<ary[a]+ary[b]+ary[c]+ary[d]+ary[e]<<endl;
                        return true;
                    }
    return false;
}

bool ok(int a,int b)
{
    int tmp=a,n=b;
    while(n)
    {
        tmp*=10;
        n/=10;
    }
    tmp+=b;
    if(bprime[tmp]) return false;
    tmp=b,n=a;
    while(n)
    {
        tmp*=10;
        n/=10;
    }
    tmp+=a;
    return !bprime[tmp];
}

set<int> se;

int main()
{
    //freopen("out.txt","w",stdout);
    bprime[0]=bprime[1]=true;
    for(int i=2; i<10000; i++)
        if(!bprime[i])
            for(int j=i<<1; j<limit; j+=i)
                bprime[j]=true;
    for(int i=2; i<10000; i++)
        if(!bprime[i])
            prime[nprime++]=i;
    int ans=0;
    for(int i=0; i<nprime; i++)
        for(int j=i+1; j<nprime; j++)
            if(ok(prime[i],prime[j]))
            {
                data[cnt++]=Edge(prime[i],prime[j]);
                //data[cnt++]=Edge(prime[j],prime[i]);
            }
    sort(data,data+cnt);
    int i=0;
    int ary[400],n;
    while(i<cnt)
    {
        se.clear();
        int x=data[i].x;
        se.insert(x);
        while(data[i].x==x)
            se.insert(data[i++].y);
        n=0;
        for(set<int>::const_iterator it=se.begin(); it!=se.end(); ++it)
            ary[n++]=*it;
        if(bingo(ary,n))
            return 0;
    }
    return 0;
}

/***
13 5197 5701 6733 8389
26033

about 9 seconds
***/
