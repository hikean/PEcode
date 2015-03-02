#include<iostream>
#include<stdio.h>

using namespace std;
const double limit=1000000;
double delt=1;
int a,b;
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int main()
{
    for(int i=10;i<=limit;i+=1)
        for(int j=(i*3.0/7.0)-3,k=3;k;k--,j+=1)
            if(gcd(i,j)==1&&i*3>j*7&&(3.0/7.0)-j*1.0/double(i)<delt)
            {
                delt=3.0/7.0-double(j)/double(i);
                a=j,b=i;
            }
    cout<<a<<"  "<<b<<" "<<delt<<endl;
    return 0;
}
