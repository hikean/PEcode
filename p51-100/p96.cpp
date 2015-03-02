#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>


using namespace std;

int data[9][9],tmp,ans=0,cnt;
bool rows[9][10]= {0},cols[9][10]= {0},rc33[3][3][10]= {0},done;

struct May
{
    int cnt,may[9],x,y;
    May():cnt(0),x(0),y(0) {}
    bool operator < (const May & b) const
    {
        return this->cnt<b.cnt;
    }
    void add(int i)
    {
        may[cnt++]=i;
    }
    void setxy(int _x,int _y)
    {
        x=_x,y=_y;cnt=0;
    }
} maybe[81];


void dfs(int lv=0)
{
    if(lv==cnt||done)
    {
        if(!done)
        {
            ans+=data[0][0]*100+data[0][1]*10+data[0][2];

            for(int i=0; i<9; i++)
            {
                for(int j=0; j<9; j++)
                    cout<<data[i][j]<<" ";
                cout<<endl;
            }

        }
        done=true;
        return ;
    }
    int x,y,s;
    x=maybe[lv].x;
    y=maybe[lv].y;
    for(int i=maybe[lv].cnt-1; i>=0; i--)
    {
        s=maybe[lv].may[i];
        if(rows[x][s]&&cols[y][s]&&rc33[x/3][y/3][s])
        {
            rows[x][s]=cols[y][s]=rc33[x/3][y/3][s]=false;
            data[x][y]=s;
            dfs(lv+1);
            rows[x][s]=cols[y][s]=rc33[x/3][y/3][s]=true;
        }
    }
}

bool read()
{
    string str;
    if(!(cin>>str)) return false;
    cin>>str;
    for(int i=0; i<9; i++)//init
        for(int j=0; j<10; j++)
            rows[i][j]=cols[i][j]=rc33[i/3][i%3][j]=true;

    for(int i=0; i<9; i++)
    {
        cin>>str;
        for(int j=0; j<9; j++)
        {
            int tmp=str[j]-'0';
            rows[i][data[i][j]=tmp]=cols[j][tmp]=rc33[i/3][j/3][tmp]=false;
        }
    }
    return true;
}

void deal()
{
    cnt=0;
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(!data[i][j])
            {
                maybe[cnt].setxy(i,j);
                for(int k=1; k<10; k++)
                    if(rows[i][k]&&cols[j][k]&&rc33[i/3][j/3])
                        maybe[cnt].add(k);
                if(maybe[cnt].cnt>0)
                    ++cnt;
            }
   // sort(maybe,maybe+cnt);// sorting  does make it faster but why ?
    done=false;// init
    dfs();
}
//24702
int main()
{
   //freopen("in.txt","r",stdin);
    while(read())
        deal();
    cout<<ans<<endl;
    return 0;
}
/**

3 0 0 2 0 0 0 0 0
0 0 0 1 0 7 0 0 0
7 0 6 0 3 0 5 0 0
0 7 0 0 0 9 0 8 0
9 0 0 0 2 0 0 0 4
0 1 0 8 0 0 0 5 0
0 0 9 0 4 0 3 0 1
0 0 0 7 0 2 0 0 0
0 0 0 0 0 8 0 0 6


1231
12
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000

***/
