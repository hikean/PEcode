#include<iostream>
#include<math.h>
using namespace std;
#define eps 0.000000001
int cnt=0;
void inline check(int a,int b,int c)
{
    int x=a*a+(b+c)*(b+c),y=b*b+(a+c)*(a+c),z=c*c+(a+b)*(a+b);
    if(y<x) x=y;
    if(z<x) x=z;
    int tmp=sqrt(x)+eps;
    if(tmp*tmp==x) cnt++;
}
int main()
{
    for(int lim=1;lim<5000;lim++)
    {
        for(int j=1;j<=lim;j++)
            for(int k=j;k<=lim;k++)
                check(lim,j,k);
        if(cnt>1000000)
        {
            cout<<lim<<endl;
            cout<<cnt<<endl;
            break;
        }
    }
    return 0;
}
