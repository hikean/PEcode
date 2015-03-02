#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
#define INF 1e9
int const limit=80;

int mat[limit][limit],cnt=0;
int dist[limit*limit+5];
bool done[limit*limit+5]= {0};
struct Edge
{
    int to,cost;
    bool operator < (const Edge & e) const
    {
        return this->cost>e.cost;
    }
    Edge(int t=0,int c=INF):to(t),cost(c) {}
} edges[limit*limit][4];
int getN()
{
    char tmp;
    int n=0;
    do
    {
        tmp=getchar();
        if(tmp>='0'&&tmp<='9')
            n=n*10+int(tmp-'0');
    }
    while(tmp>='0'&&tmp<='9');
    return n;
}

void addEdge(int x,int y,int i,int j)
{
    if(i>=limit||j>=limit||i<0||j<0) return ;
    edges[x*limit+y][cnt++]=Edge(i*limit+j,mat[i][j]);
}

void read()
{
    for(int i=0; i<limit; i++) /// read from txt
        for(int j=0; j<limit; j++)
            mat[i][j]=getN();
    ///build Graph
    for(int i=0; i<limit; i++)
        for(int j=0; j<limit; j++)
        {
            cnt=0;
            addEdge(i,j,i,j+1);
            addEdge(i,j,i,j-1);
            addEdge(i,j,i-1,j);
            addEdge(i,j,i+1,j);
        }
}

void dijkstra(int s=0)
{
    priority_queue<Edge> pque;
    for(int i=0; i<limit*limit; i++) dist[i]=INF;
    dist[s]=mat[0][0];
    pque.push(Edge(s,mat[0][0]));
    while(!pque.empty())
    {
        Edge x=pque.top();pque.pop();
        int u=x.to;
        if(done[u]) continue;
        done[u]=true;
        for(int i=0; i<4; i++)
        {
            Edge & e=edges[u][i];
            if(dist[e.to]>dist[u]+e.cost)
            {
                dist[e.to]=dist[u]+e.cost;
                pque.push(Edge(e.to,dist[e.to]));
            }
        }
    }
    cout<<dist[limit*limit-1]<<endl;
}
int main()
{
    freopen("p83in.txt","r",stdin);
    read();
    dijkstra();
    return 0;
}

