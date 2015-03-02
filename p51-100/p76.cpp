#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int cnt=101;
long long mul[cnt]={0};
long long tmp[cnt]={0};

int fact[cnt];
int main()
{
    mul[0]=1;
    for(int i=0;i<cnt;i++)
        fact[i]=i+1;
    for(int i=0;i<cnt-2;i++)
    {
        for(int i=0;i<cnt;i++)
            tmp[i]=0;
        for(int j=0;j<cnt;j+=fact[i])//j power
        {
            for(int k=0;k<cnt;k++)//k power
                if(k+j>=cnt)
                    break;
                else
                    tmp[k+j]+=mul[k];
        }
        copy(tmp,tmp+cnt,mul);
    }
    cout<<mul[cnt-1]<<endl;


    return 0;
}
