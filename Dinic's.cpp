#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e61
const int mxN=1e4;       //O(V^2*E)
struct edge
{
    int to,cap,rev;
};
vector<edge>adj[mxN];
int level[mxN];
void add_edge(int from,int to,int cap)
{
    adj[from].push_back((edge){to,cap,adj[to].size()});
    adj[to].push_back((edge){from,0,adj[from].size()-1});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int>q;q.push(s);
    level[s]=0;
    while(!q.empty())
    {
        int n=q.front();q.pop();
        for(auto i:adj[n])
        {
            edge &e=i;
            if(level[e.to]<0 and e.cap)level[e.to]=level[n]+1,q.push(e.to);
        }
    }
}
int dfs(int s,int t,int f)
{
    if(s==t)return f;
    for(int i=0;i<adj[s].size();i++)
    {
        edge &e=adj[s][i];
        if(level[s]<level[e.to] and e.cap)
        {
            ll d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                adj[e.to][e.rev].cap+=d;    //Residual graph
                return d;
            }
        }
    }
    return 0;
}
ll max_flow(int s,int t)
{
    ll flow=0,new_flow;
    while(true)
    {
        bfs(s);
        if(level[t]<0)return flow;
        while(new_flow=dfs(s,t,INF))flow+=new_flow;
    }
    return flow;
}
int main()
{
    int n,m,i,a,b,c;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        add_edge(a,b,c);
        //add_edge(b,a,c);    /*for undirected*/
    }
    cout<<max_flow(1,n)<<endl;     //source 1 and sink n
}
