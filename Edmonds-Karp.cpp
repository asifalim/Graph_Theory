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
const int mxN=515,mod=1e9+7;
vector<int>adj[mxN];                    //O(V*E^2)
ll ar[mxN][mxN];int par[mxN];
int bfs(int s,int t)
{
    mem(par,-1);
    queue<pair<int,int>>q;
    q.push({s,INF});
    while(!q.empty())
    {
        int node=q.front().first,flow=q.front().second;q.pop();
        for(auto i:adj[node])
        {
            if(ar[node][i] and par[i]==-1)
            {
                flow=min(1LL*flow,ar[node][i]);
                par[i]=node;
                if(i==t)return flow;
                q.push({i,flow});
            }
        }
    }
    return 0;
}
ll Edmonds_Karp(int s,int t)
{
    int prev,new_flow,cur;ll flow=0;
    while(new_flow=bfs(s,t))
    {
        cur=t;
        flow+=new_flow;
        while(cur!=s)
        {
            prev=par[cur];
            ar[prev][cur]-=new_flow;
            ar[cur][prev]+=new_flow;
            cur=prev;
        }
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
        for(i=1;i<=m;i++)cin>>a>>b>>c,adj[a].push_back(b),adj[b].push_back(a),ar[a][b]+=c;   //for undirected  ---> ar[b][a]+=c;
        cout<<Edmonds_Karp(1,n)<<endl;
    //}
    return 0;
}

