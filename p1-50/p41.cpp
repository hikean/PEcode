#include<iostream>
#define MAXN 8000001
using namespace std;

int bprime[MAXN]= {0};

bool used[8]={0};
int ans=0;
int level;
void dfs(int lv=0,int n=0)
{
    if(lv==level&&!bprime[n]&&n>ans)
        ans=n;
    if(lv==level) return ;
    for(int i=1;i<level+1;i++)
        if(!used[i])
        {
            used[i]=true;
            dfs(lv+1,n*10+i);
            used[i]=false;
        }
}

int main()
{
     for(int i=2;i<3000;i++)
        if(!bprime[i])
            for(int j=i*2;j<MAXN;j+=i)
                bprime[j]=true;
    for(level=4;level<8;level++)
    {
        for(int i=0;i<8;i++)
            used[i]=false;
        dfs();
    }
    cout<<ans<<endl;
    return 0;
}
