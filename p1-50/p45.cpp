#include<iostream>
#include<math.h>
using namespace std;

bool is3(int n)
{
    //n*(n+1)/2==(n*n+n)/2
    int i=sqrt(n*2);
    return i*(i+1)/2==n;
}
bool is5(int n)
{
    //n*(3n-1)
    int i=sqrt(n*2/3.0)+0.5;
    return i*(3*i-1)/2==n;
}
bool is6(int n)
{
    //n*(2n-1)
    int i=sqrt(n/2.0)+0.5;
    return i*(i*2-1)==n;

}

int main()
{

    for(int i=1;i<500000000;i++)
    {
        if(is3(i)&&is5(i)&&is6(i))
        {
            cout<<i<<endl;
        }
    }

    return 0;
}
