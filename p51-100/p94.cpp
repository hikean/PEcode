#include<iostream>
#include<math.h>
#include<stdio.h>
#include<time.h>
using namespace std;
#define eps 0.000001
const long long limit=1e9;
long long ans=0;
int main()
{
    int start=clock();
    freopen("out.txt","w",stdout);
    for(long long b,h,tmp, a=2;a<=limit/3;a++)
    {
        b=a-1;
        tmp=4*a*a-b*b;
        h=sqrt(tmp)+eps;

       if(h*h==tmp&&(h*b)%8==0)
            ans+=a+a+b;
        b=a+1;
        tmp=4*a*a-b*b;
        h=sqrt(tmp)+eps;
        if(h*h==tmp&&(h*b)%8==0)
            ans+=a+a+b;
    }
    cout<<ans<<endl;
    cout<<"time :  "<<clock()-start<<endl;
    return 0;
}
/***
518408346
a a b
b*(4*a*a +b*b)^0.5/4

***/
