#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e9
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,k=0;
const int mxN=105,mod=1e9+7;
ll cap[mxN][mxN],level[mxN],q[mxN];
int bfs(int s,int t)
{
    mem(level,-1);
    level[s]=0;
    int qh=0,qt=0;
    q[qt++]=s;
    while(qh<qt)
    {
        int v=q[qh++];
        for(int to=2; to<=t; to++)
            if(level[to]==-1 and cap[v][to])
            {
                level[to]=level[v]+1,q[qt++]=to;
                if(to==t)return true;
            }
    }
    return level[t]!=-1;
}
int dfs(int s,int t,int flow)
{
    if(!flow)return 0;
    if(s==t)return flow;
    for(int to=1; to<=t; to++)
    {
        if(level[s]+1!=level[to])continue;
        int new_flow=dfs(to,t,min(1LL*flow,cap[s][to]));
        if(new_flow)
        {
            cap[s][to]-=new_flow;
            cap[to][s]+=new_flow;
            return new_flow;
        }
    }
    return 0;
}
ll dinic(int s,int t)
{
    ll flow=0,new_flow;
    while(true)
    {
        if(!bfs(s,t))break;
        while(new_flow=dfs(s,t,INF))flow+=new_flow;
    }
    return flow;
}
signed main()
{
    //fast;
    // w(t)
    //{
    int n,m,a,b,c,d,i,j,sm=0,sm1=0,cn=0,cn1=0,mx=INT_MIN,mn=INT_MAX,mx1;
    string s,ss,sr;
    bool f=false,ff=false;
    cin>>n>>m;
    for(i=1; i<=m; i++)cin>>a>>b>>c,cap[a][b]+=c,cap[b][a]+=c;
    cout<<dinic(1,n)<<endl;
    //}
    return 0;
}
