#include<iostream>
using namespace std;

const int limit=1000000;
bool have[limit+1]= {0};
int len=0,ans;
int amicable[limit+1];
int main()
{
    for(int j,i=1; i<=limit; i++)
    {
        amicable[i]=1;
        for(j=2; j*j<i; j++)
            if(i%j==0)
                amicable[i]+=(j+i/j);
        if(j*j==i)
            amicable[i]+=j;
        if(amicable[i]>limit)
            amicable[i]=0;
    }
    for(int i=1; i<=limit; i++)
    {
        int nxt=i,cnt=0;
        while(amicable[nxt]&&!have[nxt])
        {
            have[nxt]=true;
            nxt=amicable[nxt];
            ++cnt;
            if(nxt==i)
            {
                if(len<cnt)
                {
                    len=cnt;
                    ans=i;
                }
                break;
            }
        }
        nxt=i;
         while(cnt)
        {
            have[nxt]=false;
            nxt=amicable[nxt];
            --cnt;
        }
    }
    cout<<ans<<" "<<len<<endl;
    return 0;
}
