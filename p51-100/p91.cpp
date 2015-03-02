#include<iostream>

using namespace std;

bool inline CHECK(int a,int b,int c,int d)
{
    int x=a*a+b*b,y=c*c+d*d,z=(a-c)*(a-c)+(b-d)*(b-d);
    return x+y==z||z+y==x||x+z==y;
}
const int limit=50;
int main()
{
    int ans=0;
    for(int x1=0;x1<=limit;++x1)
        for(int y1=0;y1<=limit;y1++)
            for(int x2=0;x2<=limit;++x2)
                for(int y2=0;y2<=limit;y2++)
        if(x1+y1!=0 && x2+y2!=0&& y2*x1!=x2*y1&&CHECK(x1,y1,x2,y2))
            ans++;
    cout<<ans/2<<endl;/***  divided by 2 is necessary ***/
    return 0;
}
