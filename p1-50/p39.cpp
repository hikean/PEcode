#include<iostream>

using namespace std;

int cnt[1000+5]= {0};
int main()
{
    for(int i=1; i<500; i++)
        for(int j=i; j<500; j++)
            for(int k=j; k<500; k++)
                if(i*i+j*j==k*k && i+j+k<=1000)
                    cnt[i+j+k]++;
    int ans=0,len=0;
    for(int i=1; i<=1000; i++)
        if(cnt[i]>len)
            len=cnt[ans=i];
    cout<<ans<<endl;
    return 0;
}
