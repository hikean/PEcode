#include<algorithm>
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<time.h>
#define mod 1000000
using namespace std;
//product function
const int limit=60000;///55374
int mul[limit+5]= {0}, tmp[limit+5]= {0},cnt=0;
int main()
{
    int start=clock();
    freopen("outp78.txt","w",stdout);
    for(int i=0; i<=limit; i++)
        tmp[i]=mul[i]=1;
    for(int i=2; i<limit; i++)
    {
        for(int j=i; j<=limit; j+=i) //j power
            for(int k=0; k<=limit; k++) //k power
                if(k+j>limit)
                    break;
                else
                {
                    tmp[k+j]+=mul[k];
                    tmp[k+j]%=mod;
                }
        copy(tmp,tmp+limit,mul);
        if(mul[i]%mod==0)
        {
            cout<<i<<endl;
            cout<<"Time : "<<clock()-start<<endl;
            break;
        }
    }
    return 0;
}

/***

55374
Time : 298853ms

***/
