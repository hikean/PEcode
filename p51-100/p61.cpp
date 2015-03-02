#include<iostream>

using namespace std;
inline int cal(int n,int i)
{
    if(i<=4)
        return i==3?(n+1)*n/2:n*n;//3 4
    if(i>6)
        return i==7?n*(5*n-3)/2:n*(3*n-2);//7 8
    return i==5?n*(3*n-1)/2:n*(2*n-1);//5 6
}
int rs[9][2]= {0,0,0,0,0,0,45,141,32,100,26,82,23,71,21,64,19,59};
bool used[10]= {0},goon=true;
int num[10],cnt=0,seq[10],nn[10];
void dfs()
{
    if(!goon) return ;
    if(cnt==6)
    {
        for(int i=0; i<6; i++)
            if(num[i]%100!=num[(i+1)%6]/100)
                return ;
        goon=false;
        int ans=0;
        for(int i=0; i<6; i++)
        {
            cout<<num[i]<<"   "<<seq[i]<<"  "<<nn[i]<<" "<<endl;
            ans+=num[i];
        }
        cout<<"sum "<<ans<<endl;
    }
    for(int i=8; i>2; i--)
        if(!used[i])
        {
            used[i]=true;
            seq[cnt]=i;
            for(int j=rs[i][0]; j<rs[i][1]; j++)
            {
                nn[cnt]=j;
                num[cnt++]=cal(j,i);
                if(cnt>1&&num[cnt-2]%100==num[cnt-1]/100)
                    dfs();
                else if(cnt==1)
                    dfs();
                --cnt;
            }
            used[i]=false;
        }
}

int main()
{
    dfs();
    return 0;
}

/****



if(i==3) return (n+1)*n/2;
    if(i==4) return n*n;
    if(i==5) return n*(3*n-1)/2;
    if(i==6) return n*(2*n-1);
    if(i==7) return n*(5*n-1)/2;
    if(i==8) return n*(3*n-2);

***/
/***

45 141
32 100
26 82
23 71
21 64
19 59
    ***/
